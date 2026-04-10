# Module 1: The First Pull Request

Welcome to your first task! The goal of this module is to get used to the fundamental Git workflow: **Branch** -> **Commit** -> **Push** -> **Pull Request**.

## Task Objective

Your objective is to add your name to the hall of fame list in `CONTRIBUTORS.md`.

## Walkthrough

### 1. Make Sure You Are on `main`
First, ensure you are on the primary branch and your local repo is up-to-date.
```bash
git checkout main
# or git switch main
git pull
```

### 2. Create a Feature Branch
In a team environment, no one commits to `main` directly.

Create a branch uniquely named for this task (e.g., `add-name-<your-username>`):
```bash
git branch add-name-<your-username>
git checkout add-name-<your-username>

# Short version for Both:
# git checkout -b add-name-<your-username>
# git switch -c add-name-<your-username>
```

### 3. Make Your Change
Open the file `CONTRIBUTORS.md` in your text editor. Add a new row to the markdown table with your Name and GitHub username!

### 4. Stage and Commit
Check the files you modified.
```bash
git status
```
Stage the file for commit:
```bash
git add CONTRIBUTORS.md
```
Create a commit with a clear, concise message:
```bash
git commit -m "docs: add <your-username> to contributors list"
```

### 5. Push Your Branch
Push your newly created branch up to your forked repository.
```bash
git push -u origin add-name-<your-username>
```

### 6. Open a Pull Request!
Go to GitHub, and you'll see a green "Compare & pull request" button. Click it, review your changes, and submit the PR.

Congratulations, you've completed your first open-source style contribution!

➡️ **Next Up:** [Module 2: Branching & Merging](./02-BRANCHING-MERGING.md)
