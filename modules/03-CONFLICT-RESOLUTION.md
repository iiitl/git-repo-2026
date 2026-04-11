# Module 3: Conflict Resolution

Merge conflicts are universally feared by beginners, but they are a completely normal part of collaboration. They happen when two sets of changes touch **the exact same lines** of a file and Git cannot determine which version to keep — so it asks you to decide.

This is one of the most important skills you'll learn — conflicts come up every day in real projects.

## Task Objective

Simulate a real-world scenario: someone else merges a change into `main` while you are working on your feature branch. Your branch now conflicts with `main`. You will resolve the conflict locally, then push your fixed branch and open a Pull Request.

## Walkthrough

### 1. Start on `main`
Make sure you are on `main` and it is up to date:
```bash
git switch main
git pull
```

### 2. Create Your Feature Branch
Create a branch for your work, then add the starting config file directly on it:
```bash
git switch -c feature/update-config
```
Create a file named `config.txt` in the root of your repo with this single line:
```text
APP_ENVIRONMENT=production
```
This file represents shared configuration that multiple developers might edit. Commit it as the common starting point:
```bash
git add config.txt
git commit -m "chore: add default config.txt"
```

### 3. Simulate a Teammate's Parallel Branch
In a real project, a teammate would branch off from the same commit and make their own changes. Simulate that now — create a second branch from this exact point:
```bash
git switch -c teammate/update-config
```
Open `config.txt` and change the line to:
```text
APP_ENVIRONMENT=staging
```
Commit it as if your teammate did this work:
```bash
git add config.txt
git commit -m "fix: set environment to staging"
```
Now switch back to your own feature branch:
```bash
git switch feature/update-config
```

### 4. Make Your Change
Open `config.txt` and change the line to:
```text
APP_ENVIRONMENT=development
```
Stage and commit:
```bash
git add config.txt
git commit -m "fix: set environment to development"
```
Your branch has `development`. The teammate's branch has `staging`. Both diverged from the same starting commit — both changed the same line in different ways.

### 5. Merge the Teammate's Branch — and Trigger the Conflict
In the real world, a teammate's PR gets merged into `main` before yours, and you need to incorporate those changes. Simulate that by merging the teammate's branch into yours:
```bash
git merge teammate/update-config
```
**💥 Conflict!** You will see a message like:
```
CONFLICT (content): Merge conflict in config.txt
Automatic merge failed; fix conflicts and then commit the result.
```
This is completely expected. Git is saying: *"I see two different values for the same line — `development` (your branch) and `staging` (teammate's branch). Which one should win? I need you to decide."*

### 6. Open the Conflicted File and Resolve It
Open `config.txt` in your text editor. It now looks like this:
```
<<<<<<< HEAD
APP_ENVIRONMENT=development
=======
APP_ENVIRONMENT=staging
>>>>>>> teammate/update-config
```
Here is what each section means:
- Between `<<<<<<< HEAD` and `=======` → **your change** (what is on your feature branch)
- Between `=======` and `>>>>>>> teammate/update-config` → **the incoming change** from the teammate's branch

To resolve it:
1. **Delete all three marker lines** (`<<<<<<<`, `=======`, `>>>>>>>`) — Git added these temporarily and they must not stay in the file
2. **Keep the final content you want as the result**

For this exercise, keep `development` as the winner:
```text
APP_ENVIRONMENT=development
```
Save the file.

### 7. Finalize the Resolution
Tell Git you resolved the conflict by staging the fixed file:
```bash
git add config.txt
```
Complete the merge with a commit:
```bash
git commit -m "fix: resolve env conflict, keep development setting"
```
Run `git log --oneline` to review your branch history. You will see the initial config commit, your development change, and the merge commit — proving your branch now incorporates the teammate's work.

### 8. Push Your Branch and Open a Pull Request
Push your resolved branch to your fork:
```bash
git push -u origin feature/update-config
```
Go to GitHub and open a PR:
- **base repository**: the original upstream repo
- **base**: `main`
- **compare**: `feature/update-config`

In the PR description write something like: *"Resolved a merge conflict with a teammate's branch. Keeping `APP_ENVIRONMENT=development`."*

Click **"Create pull request"**. 🎉 You survived your first conflict!

➡️ **Next Up:** [Module 4: Commit Squashing](./04-SQUASHING.md)