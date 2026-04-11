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
Your *local* `main` is up to date, but your fork on GitHub (`origin`) is still behind! Push your freshly synced `main` up to your fork:
```bash
git push origin main
```
Your fork is now fully in sync. It is best practice to do this **every day** before you start working on a new feature branch.

### 6. Prove It: Open a PR from a Synced Fork
Let's confirm everything works correctly by creating a branch and opening a small PR.

Create a new branch:
```bash
git switch -c sync/verify-<your-username>
```
Create a new folder called `sync-notes/` inside the repo, and add a file named `<your-username>.md` inside it with this content:
```markdown
# Sync Verified

- **Username:** <your-username>
- **Date synced:** <today's date>
```
Stage, commit, and push:
```bash
git add .
git commit -m "chore: verify fork sync for <your-username>"
git push -u origin sync/verify-<your-username>
```
Go to GitHub and open a Pull Request:
- **base repository**: the original upstream repo
- **base**: `main`
- **compare**: `sync/verify-<your-username>`

Click **"Create pull request"**. ✅

This PR proves your fork was properly synced before branching — a clean, conflict-free workflow!

🎉 **You have completed all modules!** You now have a fully synced fork and the skills to contribute to any open-source project with confidence.