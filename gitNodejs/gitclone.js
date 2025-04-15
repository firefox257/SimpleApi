// Import necessary modules using require
const git = require('isomorphic-git');
const http = require('isomorphic-git/http/node'); // Node.js HTTP client
const fs = require('fs'); // Node.js file system module
const path = require('path'); // Node.js path module

// --- Configuration ---
// !! IMPORTANT: Avoid hardcoding tokens in production code.
//    Use environment variables or secure config management instead.
const GITHUB_TOKEN = 'token here'; // Replace or set environment variable
const REPO_URL = 'https://github.com/firefox257/SimpleApi'; // Replace with your repo URL
const CLONE_DIR = 'github'; // Directory to clone into



// --- Main Clone Function ---
async function cloneRepository() {
  console.log(`Attempting to clone ${REPO_URL} into ${CLONE_DIR}...`);

  try {
    await git.clone({
      fs: fs, // Pass the Node.js fs module
      http: http, // Pass the Node.js HTTP client
      dir: CLONE_DIR, // The directory to clone into
      url: REPO_URL, // The URL of the repository
      depth: 1, // Optional: Clone only the latest commit (shallow clone)
      singleBranch: true, // Optional: Clone only the default branch

      // --- Authentication Handling ---
      onAuth: (url) => {
        // This callback provides credentials when requested by the Git server
        console.log(`Authentication requested for: ${url}`);
        // For GitHub PATs over HTTPS, the token is often used as the username.
        // Some providers might require it as the password, or use different usernames like 'oauth2'.
        // Check your Git provider's documentation for token authentication specifics.
        return {
          username: GITHUB_TOKEN,
          // password: GITHUB_TOKEN // Use this if the provider requires the token as password
        };
      },
      onAuthFailure: (auth) => {
        console.error('Authentication failed!');
        // You could potentially retry with different credentials here if needed
        // based on the 'auth' object provided.
        return; // Returning undefined/void indicates failure cannot be recovered
      },
      onProgress: (progress) => {
        // Optional: Log progress events
        // console.log('Progress:', progress.phase, `${progress.loaded}/${progress.total}`);
      },
    });

    console.log(`Successfully cloned ${REPO_URL} to ${CLONE_DIR}`);
  } catch (error) {
    console.error('Failed to clone repository:');
    console.error(error);
    // Clean up the directory if cloning failed partially (optional)
    if (fs.existsSync(CLONE_DIR)) {
      // Use rmSync for Node.js v14.14+ or rmdirSync with { recursive: true } for older versions
      // Be careful with recursive deletion!
      try {
        console.log(`Cleaning up failed clone directory: ${CLONE_DIR}`);
        // fs.rmSync(CLONE_DIR, { recursive: true, force: true }); // Node >= 14.14
        fs.rmdirSync(CLONE_DIR, { recursive: true });          // Node < 14.14 but >= 12.10
      } catch (cleanupError) {
        console.error(`Error cleaning up directory: ${cleanupError}`);
      }
    }
  }
}

// --- Execute the Clone ---
cloneRepository();
