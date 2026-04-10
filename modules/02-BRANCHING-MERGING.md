# Module 2: Branching & Merging

When working on a large application, different tasks are split up among developers using branches. Sometimes they are simple feature additions, and sometimes they involve merging diverging pathways.

## Task Objective

Create a small greeting script, commit it to a feature branch, and then merge it locally back into your `main` branch before pushing.

## Walkthrough

### 1. Branching Out
Make sure your `main` branch is up to date, then create a new branch:
```bash
git switch main
git pull
git switch -c feature/hello-world
```

### 2. Add Code
Create a new directory called `src/` (if it doesn't already exist), and then create your greeting program.
For example, create `src/hello.js` or `src/hello.py`:
```python
# hello.py
print("Hello, world! I am branching out.")
```

### 3. Commit the Code
```bash
git add src/hello.*
git commit -m "feat: add hello greeting script"
```

### 4. Merging
You are currently on your `feature/hello-world` branch. We need to merge this new feature back into `main`.

First, switch back to the branch you want to merge **INTO**:
```bash
git switch main
```

Now, command Git to merge your new branch:
```bash
git merge feature/hello-world
```
Because no one else touched `main` while you were working on your feature branch, this will likely be what Git calls a **"Fast-forward" merge**. It just rapidly slides the main pointer up to your new commit.

### 5. Cleanup
We don't need the old feature branch lying around anymore! Let's delete it locally:
```bash
git branch -d feature/hello-world
```

Once merged to `main`, push to your remote:
```bash
git push origin main
```

*(Note: In most open source workflows, we don't merge into `main` locally—we do it via a Pull Request. But understanding local merges is vital for conflict resolution!)*

➡️ **Next Up:** [Module 3: Conflict Resolution](./03-CONFLICT-RESOLUTION.md)