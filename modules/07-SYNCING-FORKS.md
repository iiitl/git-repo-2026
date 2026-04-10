# Module 7: Syncing Your Fork

In Open Source and large enterprise environments, you don't commit directly to the repository—you work off a *fork*. However, while you are working on your feature, other developers are merging *their* PRs into the main codebase. 

Soon, your fork becomes "out of date" and falls behind. If you try to open a PR now, you might get ugly merge conflicts.

## Task Objective

Learn how to connect your local clone to the original "upstream" repository, fetch the latest changes that other people made, and update your fork so you are perfectly in sync.

## Walkthrough

### 1. Check Your Remotes
"Remotes" are essentially aliases for URLs of repositories in the cloud. Run this command:
```bash
git remote -v
```
You should see:
```text
origin  https://github.com/<YOUR_USERNAME>/git-repo-2026.git (fetch)
origin  https://github.com/<YOUR_USERNAME>/git-repo-2026.git (push)
```
`origin` represents *your* fork.

### 2. Add the Upstream Remote
We need to tell Git where the original repository lives. We usually call this `upstream`.
```bash
git remote add upstream https://github.com/<ORIGINAL_OWNER>/git-repo-2026.git
```
Run `git remote -v` again. You should now see both `origin` and `upstream`!

### 3. Fetch Upstream Changes
To pull down the information about what happened in the original repo while you were away, run:
```bash
git fetch upstream
```
This downloads all the new commits and branches into your local Git system temporarily.

### 4. Sync Your Main Branch
Now, let's actually apply those changes to your local `main` branch.
Make sure you are on `main`:
```bash
git switch main
```
Merge the upstream's main branch into your own:
```bash
git merge upstream/main
```
*(Note: Some developers prefer `git rebase upstream/main` here to keep history strictly linear, but merge is perfectly fine for syncing main).*

### 5. Update Your Fork on GitHub
Your *local* `main` is up to date, but your fork on GitHub (origin) is still out of date! Push your newly synced branch back up to your fork:
```bash
git push origin main
```

 Boom! You are fully synced. It is a best practice to do this **every single day** before you create a new feature branch.

➡️ **Next Up:** [Module 8: The PR Review Lifecycle](./08-CODE-REVIEWS.md)