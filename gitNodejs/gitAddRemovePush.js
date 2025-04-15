// sync-repo-with-rollback.js
const fs = require('fs');
const path = require('path');
const git = require('isomorphic-git');
const http = require('isomorphic-git/http/node');

// --- Configuration ---
const GITHUB_TOKEN = 'token here';
const REPO_DIR = "github";
const REMOTE_NAME = 'origin';
const BRANCH_NAME = 'main';
const COMMIT_AUTHOR_NAME = 'Your Name';
const COMMIT_AUTHOR_EMAIL = 'your.email@example.com';
const COMMIT_MESSAGE = 'Automated sync: Update local changes';
// --- End Configuration ---

// Pre-flight checks
if (!fs.existsSync(REPO_DIR)) {
    console.error(`Error: Repository directory not found at ${REPO_DIR}`);
    process.exit(1);
}
if (!GITHUB_TOKEN || GITHUB_TOKEN === 'YOUR_GITHUB_TOKEN') {
    console.error(`Error: GitHub token not provided. Set the GITHUB_TOKEN environment variable or update the script.`);
    process.exit(1);
}

async function syncChanges() {
    console.log(`Starting sync for directory: ${REPO_DIR}`);
    const dir = REPO_DIR;
    const ref = `refs/heads/${BRANCH_NAME}`;

    // Keep track of files intended for staging/removal for potential rollback
    let filesToResetOnError = [];
    let commitSha = null; // Track if commit was successful

    try {
        // 1. Get the status of all files
        console.log('Checking repository status...');
        const statusMatrix = await git.statusMatrix({ fs, dir });

        const filesToAdd = [];
        const filesToRemove = [];
        filesToResetOnError = statusMatrix
            .filter(([filepath, head, workdir, stage]) => {
                // Identify any file that is not in the pristine HEAD state
                // Needs adding: untracked, modified
                // Needs removing: deleted locally
                return (head === 0 && workdir === 2) || // Untracked/Added
                       (head === 1 && workdir === 2) || // Modified
                       (head === 1 && workdir === 0);   // Deleted
            })
            .map(([filepath]) => filepath); // Get just the filepaths

        if (filesToResetOnError.length === 0) {
            console.log('No local changes detected.');
            return; // Nothing to do
        }

        console.log(`Found ${filesToResetOnError.length} changed files to process.`);

        // Separate files for add/remove based on detailed status
        for (const [filepath, head, workdir, stage] of statusMatrix) {
             // Files needing 'git add' (Untracked, Modified)
            if ((head === 0 && workdir === 2 && stage === 0) || // Untracked
                (head === 1 && workdir === 2)) { // Modified (covers stage 1, 2, etc.)
                console.log(`  + Scheduling for add/stage: ${filepath}`);
                filesToAdd.push(filepath);
            }
             // Files needing 'git remove' (Deleted from workdir but present in HEAD)
            else if (head === 1 && workdir === 0) {
                console.log(`  - Scheduling for removal: ${filepath}`);
                filesToRemove.push(filepath);
            }
             // Log other statuses if needed for debugging
             // else { console.log(`  ? Status [H,W,S]=[${head},${workdir},${stage}] for ${filepath}`); }
        }


        // 2. Stage the changes
        // Only proceed if there are files identified
        if (filesToAdd.length > 0 || filesToRemove.length > 0) {
            console.log(`Staging ${filesToAdd.length} additions/modifications and ${filesToRemove.length} removals...`);
            for (const filepath of filesToAdd) {
                await git.add({ fs, dir, filepath });
            }
            for (const filepath of filesToRemove) {
                await git.remove({ fs, dir, filepath });
            }
            console.log('Staging complete.');
        } else {
             console.log('No files needed explicit staging (might be already staged externally).');
             // If filesToResetOnError > 0 but add/remove are empty, it implies changes might already be staged.
             // The commit below will capture them.
        }


        // 3. Commit the changes (only if something was staged or identified as changed)
         if (filesToResetOnError.length > 0) { // Commit if any changes were detected initially
            console.log('Committing changes...');
            commitSha = await git.commit({ // Store SHA
                fs,
                dir,
                author: {
                    name: COMMIT_AUTHOR_NAME,
                    email: COMMIT_AUTHOR_EMAIL,
                },
                message: COMMIT_MESSAGE,
            });
            console.log(`Committed changes with SHA: ${commitSha}`);
        } else {
             console.log('Skipping commit as no changes were staged.');
             return; // Exit successfully if no changes needed commit
        }

        // 4. Push the changes
        console.log(`Pushing commit ${commitSha} to ${REMOTE_NAME}/${BRANCH_NAME}...`);
        const pushResult = await git.push({
            fs,
            http,
            dir,
            remote: REMOTE_NAME,
            ref: BRANCH_NAME,
            onAuth: (url) => {
                console.log(`Authenticating for: ${url}`);
                return { username: GITHUB_TOKEN };
            },
        });

        if (pushResult.ok) {
            console.log(`Successfully pushed commit ${commitSha} to ${REMOTE_NAME}/${BRANCH_NAME}.`);
            if (pushResult.errors && pushResult.errors.length > 0) {
                console.warn('Push reported non-fatal errors:', pushResult.errors);
            }
        } else {
            throw new Error(`Push failed: ${pushResult.errors ? pushResult.errors.join(', ') : 'Unknown reason'}`);
        }

        console.log('Sync process completed successfully.');

    } catch (error) {
        console.error('\n--- ERROR DURING GIT SYNC ---');
        console.error(`Failed step: ${error.caller || 'Detection Point unclear'}`);
        console.error('Error message:', error.message);
        // Don't log the full stack in the common case unless debugging, message is usually enough
        // console.error('Stack trace:', error.stack);

        // --- Attempt Rollback ---
        if (filesToResetOnError.length > 0) {
            console.warn('\n--- ATTEMPTING ROLLBACK ---');
            console.warn('Resetting index and working directory for changed files to HEAD state...');
            console.warn('WARNING: This will discard local modifications for the affected files!');
            try {
                // Use git.checkout to reset specified files to HEAD state
                // This affects both the index and the working directory for these files.
                await git.checkout({
                    fs,
                    dir,
                    ref: 'HEAD', // Reset to the last commit
                    filepaths: filesToResetOnError, // List of files identified as changed
                    force: true // Needed to overwrite working directory changes
                });
                console.log('Rollback successful: Affected files reset to HEAD.');
            } catch (checkoutError) {
                console.error('--- ROLLBACK FAILED ---');
                console.error('Could not reset files using git.checkout.');
                console.error('Error:', checkoutError.message);
                console.error('Repository might be in an inconsistent state. Manual check recommended (e.g., `git status`, `git reset HEAD`, `git checkout .`).');
            }
        } else if (commitSha) {
             // If commit succeeded but push failed, the commit exists locally.
             // Rollback is trickier here. Usually, you just leave the local commit and try pushing later.
             // Or you could 'git reset --soft HEAD~1' to undo the commit but keep changes staged.
             // For simplicity, we won't automatically reset the commit here.
             console.warn('\n--- ACTION REQUIRED ---');
             console.warn(`Commit ${commitSha} was created locally but push failed.`);
             console.warn('The local commit needs to be pushed manually or reset (e.g., `git push` or `git reset HEAD~1`).');

        } else {
            console.warn('\n--- No rollback action taken (no files were staged or error occurred early). ---');
        }

        console.error('--- SYNC HALTED DUE TO ERROR ---');
        process.exitCode = 1; // Indicate failure
    }
}

// Run the synchronization function
syncChanges();
