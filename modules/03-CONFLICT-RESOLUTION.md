# Module 3: Conflict Resolution

Merge conflicts are universally feared by beginner developers, but they are a normal part of collaboration. They happen when multiple people edit **the exact same lines** of a file, and Git doesn't know whose changes to keep.

## Task Objective

We are going to purposefully cause a merge conflict and manually resolve it using your editor.

## Walkthrough

### 1. The Setup (Creating A File)
If you aren't on `main`, switch to it.
```bash
git switch main
```
Create a file named `config.txt` inside the root of your repo. Add this one line to it:
```text
APP_ENVIRONMENT=production
```
Commit it:
```bash
git add config.txt
git commit -m "chore: add default config.txt"
```

### 2. Diverging Path A
Let's pretend Developer A makes a change. Create a branch and modify the file:
```bash
git switch -c change-a
```
Change `config.txt` to:
```text
APP_ENVIRONMENT=development
```
Commit it:
```bash
git commit -am "fix: set environment to development"
```

### 3. Diverging Path B
Now switch back to `main`, pretending to be Developer B! Developer B doesn't know Developer A changed the file.
```bash
git switch main
git switch -c change-b
```
Change `config.txt` again on this new branch to:
```text
APP_ENVIRONMENT=staging
```
Commit it:
```bash
git commit -am "fix: set environment to staging"
```

### 4. The Crash (Merging)
Developer A easily merges into `main`:
```bash
git switch main
git merge change-a
```
Developer B tries to merge now:
```bash
git merge change-b
```
**💥 BOOM! Merge Conflict!** You should see an error stating: `Automatic merge failed; fix conflicts and then commit the result.`

### 5. Resolving The Conflict
Open `config.txt`. You will see something like this:
```text
<<<<<<< HEAD
APP_ENVIRONMENT=development
=======
APP_ENVIRONMENT=staging
>>>>>>> change-b
```
- `<<<<<<< HEAD` (What is currently in `main` / Developer A's change)
- `=======` (The divider)
- `>>>>>>> change-b` (What Developer B wants to introduce)

Your job as the resolver is to **delete the Git marker lines** and decide the final state. 
Modify the file to look like this:
```text
APP_ENVIRONMENT=staging
```
Save the file.

### 6. Finalize the Merge
Tell Git you fixed it by staging the file and committing!
```bash
git add config.txt
git commit -m "Merge branch 'change-b' into main (resolved env conflict)"
```

You are officially a conflict survivor! 

➡️ **Next Up:** [Module 4: Commit Squashing](./04-SQUASHING.md)