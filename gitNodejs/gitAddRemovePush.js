// Import necessary modules
const git = require('isomorphic-git');
const http = require('isomorphic-git/http/node'); // HTTP client for pushing
const fs = require('fs'); // Use Node.js built-in fs

// --- Configuration ---
const repoDir = 'github'; // IMPORTANT: Change to your repository path
const remoteName = 'origin'; // Usually 'origin'
const branchName = 'main'; // Or 'master', or your target branch
const repoUrl = 'https://github.com/firefox257/nodejsgame1'; // IMPORTANT: Change to your repo URL
const gitHubToken = 'token here'; // IMPORTANT: Use env var or replace securely
const commitMessage = 'Automated commit and push';
const authorName = 'Your Name';
const authorEmail = 'your.email@example.com';
// --- End Configuration ---

// Helper function to log messages
const log = (message) => console.log(`[${new Date().toISOString()}] ${message}`);

// Main async function to perform Git operations
async function syncChanges() {
    log('Starting repository sync process...');

    if (!gitHubToken || gitHubToken === 'YOUR_GITHUB_TOKEN') {
        console.error("Error: GitHub token not set. Please set the GITHUB_TOKEN environment variable or update the script.");
        return; // Exit if token is not configured
    }

    // --- 1. Stage all changes (additions, modifications, deletions) ---
    try {
        log(`Staging all changes in directory: ${repoDir}`);
        // git.add with '.' stages all unstaged changes, including removals.
        await git.add({
            fs,
            dir: repoDir,
            filepath: '.', // Stage everything within the directory
        });
        log('Staging successful.');
    } catch (error) {
        console.error('Error during staging:', error);
        log('Aborting sync process due to staging error.');
        // Note: Staging might be partially complete. Manual cleanup might be needed.
        return; // Stop the process
    }

    // --- Check if there's anything to commit ---
    // Get status to see if staging resulted in changes to be committed
    let hasChangesToCommit = false;
    try {
        const status = await git.statusMatrix({ fs, dir: repoDir });
        // Check if any file has a status indicating it's staged (index status != 0 and != 1)
        // Status codes: HEAD(0), WORKDIR(1), STAGE(2)
        // Staged states include: added(0,2,2), modified(1,2,2), deleted(1,0,0->needs remove), staged but modified(1,2,3), etc.
        // We look for files where the stage status indicates a change compared to HEAD
        hasChangesToCommit = status.some(row => row[2] !== row[0]); // If stage status differs from head status

        if (!hasChangesToCommit) {
            log('No changes staged for commit. Nothing to do.');
            return; // Exit gracefully
        }
        log('Changes detected for commit.');
    } catch (error) {
        console.error('Error checking status before commit:', error);
        log('Aborting sync process due to status check error.');
        return;
    }


    // --- 2. Commit staged changes ---
    let commitSha;
    try {
        log(`Committing changes with message: "${commitMessage}"`);
        commitSha = await git.commit({
            fs,
            dir: repoDir,
            message: commitMessage,
            author: {
                name: authorName,
                email: authorEmail,
            },
            // committer is often the same as author for simple scripts
            committer: {
                name: authorName,
                email: authorEmail,
            }
        });
        log(`Commit successful. SHA: ${commitSha}`);
    } catch (error) {
        console.error('Error during commit:', error);
        log('Aborting sync process due to commit error.');
        // Note: If commit failed, staged changes remain staged.
        return; // Stop the process
    }

    // --- 3. Push changes to the remote repository ---
    try {
        log(`Pushing branch '${branchName}' to remote '${remoteName}' (${repoUrl})`);
        const pushResult = await git.push({
            fs,
            http, // Pass the HTTP client
            dir: repoDir,
            remote: remoteName,
            ref: branchName, // Push the specific branch
            url: repoUrl, // Provide URL for push (isomorphic-git sometimes needs it explicitly)
            onAuth: () => ({ // Authentication callback
                username: gitHubToken, // For GitHub PAT, the username can be the token itself or 'x-access-token'
                // password: '', // Password field is often ignored when username is a token, but provide if needed by provider
                // Or for GitHub PATs, often use:
                // username: 'oauth2accesstoken', // A common convention for tokens
                // password: gitHubToken
            }),
            // Use force: true carefully if you need to overwrite remote history (not recommended generally)
            // force: false,
        });

        log('Push successful.');
        if (pushResult && pushResult.ok && pushResult.ok.length > 0) {
             log(`Remote refs updated: ${pushResult.ok.join(', ')}`);
        } else if (pushResult && pushResult.errors && pushResult.errors.length > 0) {
             log(`Push reported errors: ${pushResult.errors.join(', ')}`);
        } else {
            log('Push completed, but no specific refs reported as updated (this might be normal).');
        }

    } catch (error) {
        console.error('Error during push:', error);
        log('Push operation failed.');
        // --- Potential Rollback (Informational) ---
        // If the push fails, the commit (commitSha) is still local.
        // You *could* try to reset the local branch:
        // log(`Attempting to roll back local commit ${commitSha}...`);
        // try {
        //   await git.reset({ fs, dir: repoDir, ref: 'HEAD~1', mode: 'hard' });
        //   log('Local commit rolled back.');
        // } catch (resetError) {
        //   console.error('Failed to roll back local commit:', resetError);
        //   log('Manual intervention may be required to clean up the local repository.');
        // }
        // CAUTION: Automating 'git reset --hard' is risky. It discards changes.
        // For this script, we are just logging the push error.
        log('The commit remains local. Manual push or reset may be required.');
        // --- End Potential Rollback ---
        return; // Stop the process
    }

    log('Repository sync process completed successfully.');
}

// Execute the main function
syncChanges();
