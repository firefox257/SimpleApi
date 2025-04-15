// sync-repo.js
const git = require('isomorphic-git');
const http = require('isomorphic-git/http/node'); // Use Node.js HTTP client
const fs = require('fs');
const path = require('path');

// --- Configuration ---
// !!! IMPORTANT: DO NOT hardcode tokens in production code.
// Use environment variables or a secure config management system.
const GITHUB_TOKEN = 'token here'; // Replace or set environment variable
const REPO_DIR = "github"; // Path to your local repository clone
const REMOTE_URL = 'https://github.com/firefox257/SimpleApi'; // HTTPS URL of your remote repository
const BRANCH_NAME = 'master'; // Or 'master', or the branch you want to push to
const COMMIT_MESSAGE = `Automated commit: ${new Date().toISOString()}`;
const AUTHOR_NAME = 'Aaron';
const AUTHOR_EMAIL = 'your.email@example.com';
// --- End Configuration ---

// Helper function to check if the token is set
function checkToken() {
    if (!GITHUB_TOKEN || GITHUB_TOKEN === 'YOUR_GITHUB_TOKEN_HERE') {
        console.error(`
  **********************************************************************
  ERROR: GitHub token is not set!
  Please set the YOUR_GITHUB_TOKEN environment variable or replace
  'YOUR_GITHUB_TOKEN_HERE' in the script.
  NEVER commit your token directly into your version control history.
  **********************************************************************
  `);
        process.exit(1); // Exit the script
    }
}

// Main async function to perform git operations
async function syncChanges() {
    checkToken(); // Check if the token is configured

    console.log(`Starting sync process for directory: ${REPO_DIR}`);

    try {
        // 1. Get the status matrix to determine changes
        console.log('Checking repository status...');
        const statusMatrix = await git.statusMatrix({ fs, dir: REPO_DIR });

        const filesToAdd = [];
        const filesToRemove = [];

        statusMatrix.forEach(([filepath, headStatus, workdirStatus, stageStatus]) => {
            // Determine status relative to the index (staging area)
            // See status codes: https://isomorphic-git.org/docs/en/statusMatrix

            // Files that are deleted in the working directory but present in HEAD/Index need removal
            if (workdirStatus === 0 && (headStatus !== 0 || stageStatus !== 0)) {
                filesToRemove.push(filepath);
            }
            // Files that are new, modified, or otherwise changed in the working directory need adding
            else if (workdirStatus > 0 && workdirStatus !== stageStatus) {
                 // Includes new files (head=0, workdir=2, stage=0) -> add
                 // Includes modified files (head=1, workdir=2, stage=1) -> add
                 // Includes files added to index but modified again (head=*, workdir=*, stage=2) -> add
                filesToAdd.push(filepath);
            }
        });

        console.log(`Files to add/update: ${filesToAdd.length}`);
        console.log(`Files to remove: ${filesToRemove.length}`);

        // Check if there are any changes to commit
        if (filesToAdd.length === 0 && filesToRemove.length === 0) {
            console.log('No changes detected in the working directory. Nothing to commit or push.');
            return; // Exit early if no changes
        }

        // 2. Stage removals
        if (filesToRemove.length > 0) {
            console.log('Staging removals...');
            await Promise.all(filesToRemove.map(filepath =>
                git.remove({ fs, dir: REPO_DIR, filepath })
            ));
            console.log('Removals staged.');
        }

        // 3. Stage additions/modifications
        if (filesToAdd.length > 0) {
            console.log('Staging additions/modifications...');
            await Promise.all(filesToAdd.map(filepath =>
                git.add({ fs, dir: REPO_DIR, filepath })
            ));
            console.log('Additions/modifications staged.');
        }

        // 4. Commit the staged changes
        console.log('Committing changes...');
        const commitSha = await git.commit({
            fs,
            dir: REPO_DIR,
            message: COMMIT_MESSAGE,
            author: {
                name: AUTHOR_NAME,
                email: AUTHOR_EMAIL,
            },
            // Committer can be the same or different (e.g., the script/bot)
            // committer: {
            //   name: 'Sync Bot',
            //   email: 'bot@example.com',
            // }
        });
        console.log(`Changes committed successfully. SHA: ${commitSha}`);

        // 5. Push the commit to the remote repository
        console.log(`Pushing changes to remote: ${REMOTE_URL} branch: ${BRANCH_NAME}...`);

        // Define the authentication callback
        const onAuth = (url) => {
            // For GitHub token authentication over HTTPS
            // The password field is used for the token
            console.log(`Authentication requested for: ${url}`);
            return {
                username: GITHUB_TOKEN, // Use the token as the username (or password, both work for GitHub PAT)
                // password: GITHUB_TOKEN // Alternatively, you can sometimes use it here. Username method is common.
            };
        };

        const pushResult = await git.push({
            fs,
            http, // Pass the Node HTTP client
            dir: REPO_DIR,
            url: REMOTE_URL, // Use the remote URL directly
            ref: BRANCH_NAME, // Specify the local branch to push
            remoteRef: `refs/heads/${BRANCH_NAME}`, // Specify the remote branch
            force: false, // Set to true if you need to force push (use with caution!)
            onAuth: onAuth, // Provide the authentication callback
        });

        console.log('Push result:', pushResult);
        if (pushResult.ok) {
            console.log('Changes pushed successfully!');
        } else {
            console.error('Push failed:', pushResult.errors);
            throw new Error(`Push failed: ${pushResult.errors.join(', ')}`);
        }

    } catch (error) {
        console.error('An error occurred during the git sync process:', error);
        process.exitCode = 1; // Indicate failure
    }
}

// --- Run the sync process ---
syncChanges();
