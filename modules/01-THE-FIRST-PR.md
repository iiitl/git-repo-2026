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
Go to your browser and navigate to **your fork** on GitHub:
```
https://github.com/<YOUR_USERNAME>/git-repo-2026
```

You will see a yellow banner at the top saying **"Your recently pushed branches:"** with a green **"Compare & pull request"** button next to your branch name. Click it.

On the Pull Request creation page, check these settings **before** clicking submit:

- **base repository** → must be the **original** repo (e.g., `<ORIGINAL_OWNER>/git-repo-2026`), **not** your own fork
- **base** → `main`
- **head repository** → your fork (`<YOUR_USERNAME>/git-repo-2026`)
- **compare** → `add-name-<your-username>`

> If the base repository is set to your own fork by default, click **"compare across forks"** to switch it to the original upstream repo.

Give your PR a clear title like `docs: add <your-username> to contributors list`, add a short description of what you changed, and click **"Create pull request"**.

Congratulations — you have opened your first Pull Request! 🎉

➡️ **Next Up:** [Module 2: Branching & Merging](./02-BRANCHING-MERGING.md)
