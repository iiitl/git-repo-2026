# Module 2: Branching & Merging

When working on a large project, each new feature or fix is built in isolation on its own **branch**. This prevents half-finished work from breaking the shared `main` branch. Once the work is done, it gets merged into `main` — in real projects this always happens through a Pull Request, never directly.

## Task Objective

Create a small greeting script on a feature branch, push it to your fork, and open a Pull Request. Along the way you will learn what branches are and how merging works under the hood.

## 🔄 Keeping Your Fork in Sync

When you fork this repository, your fork is a snapshot of the original at that moment. As other contributors open Pull Requests and maintainers merge them, the original ("upstream") repository moves ahead — and your fork falls behind.

**Upstream** is the name Git uses for the original repository your fork was created from. Before starting any new feature branch you should pull the latest changes from upstream into your local `main` so your work is always based on the most current code. Skipping this step is the most common cause of avoidable merge conflicts.

For a full walkthrough on how to add the upstream remote, fetch changes, and keep your fork perfectly in sync, see [Module 7: Syncing Your Fork](./07-SYNCING-FORKS.md).

---

## Walkthrough

### 1. Start Fresh on `main`
Always begin a new task from an up-to-date `main` branch. Switch to `main` and pull the latest changes:
```bash
git switch main
git pull
```

### 2. Create a Feature Branch
A branch is an independent line of development — think of it as a safe copy of `main` where you can make changes without affecting anyone else.

Create a new branch and switch to it in one command:
```bash
git switch -c feature/hello-world
```
You are now on a branch called `feature/hello-world`. Run the following command to confirm — the branch marked with `*` is the one you are currently on:
```bash
git branch
```

### 3. Add Your Code
Create a new folder called `src/` inside the repo root, then add a greeting file inside it.

For example, create `src/hello.py`:
```python
# hello.py
print("Hello, world! I am branching out.")
```
Or if you prefer JavaScript, create `src/hello.js`:
```javascript
// hello.js
console.log("Hello, world! I am branching out.");
```

### 4. Stage and Commit
Check what files Git sees as changed:
```bash
git status
```
Stage all your changes:
```bash
git add .
```
Commit with a clear, descriptive message:
```bash
git commit -m "feat: add hello greeting script"
```

### 5. Push Your Branch to GitHub
Your branch currently only exists on your local machine. Push it up to your fork so GitHub can see it:
```bash
git push -u origin feature/hello-world
```
> The `-u` flag links your local branch to the remote one. From now on, while on this branch, a plain `git push` is enough — no need to specify the remote or branch name each time.

### 6. Open a Pull Request
Go to your browser and navigate to your fork on GitHub:
```
https://github.com/<YOUR_USERNAME>/git-repo-2026
```
You will see a yellow banner: **"Your recently pushed branches:"** with a green **"Compare & pull request"** button. Click it.

On the PR creation page, verify the following before submitting:
- **base repository** → the original upstream repo (e.g., `<ORIGINAL_OWNER>/git-repo-2026`), **not** your own fork
- **base** → `main`
- **compare** → `feature/hello-world`

Give your PR a descriptive title like `feat: add hello greeting script`, then click **"Create pull request"**. ✅

---

## 💡 Concept: What Does "Merging" Actually Mean?

When a maintainer clicks **"Merge pull request"** on GitHub, Git runs these commands behind the scenes:
```bash
git switch main
git merge feature/hello-world
```
Because no one else changed `main` while you were working, this is a **fast-forward merge** — Git simply slides the `main` pointer forward to include your new commit. No conflicts, no complications.

**Do not run this locally.** Merging into your local `main` before the PR is merged upstream will cause your history to diverge from the upstream repository, which breaks fork syncing. Let the PR on GitHub handle the merge — once a maintainer merges it, pull the updated `main` from upstream instead:
```bash
git switch main
git pull upstream main
```
Your local `main` now matches upstream exactly, and `git log --oneline` will show the merged commit just as GitHub recorded it.

After a PR is merged on GitHub, clean up the old branch both locally and on your fork:
```bash
# Delete the local branch
git branch -d feature/hello-world

# Delete the remote branch on your fork
git push origin --delete feature/hello-world
```

➡️ **Next Up:** [Module 3: Conflict Resolution](./03-CONFLICT-RESOLUTION.md)