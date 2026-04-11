# Module 4: Squashing Commits

When contributing to a large codebase, one feature might take you a dozen tiny commits. However, maintainers typically want a **clean history**. They usually ask you to "squash" these minor commits ("WIP", "fixed a typo", "try again") down to a single logical commit before accepting a Pull Request.

## Task Objective

Create a series of messy commits on a branch, then use **Interactive Rebase** to squash them into one neat commit.

## Walkthrough

### 1. The Setup (Creating Messy Commits)
From `main`, create a new branch:
```bash
git switch main
# Ensure you are up-to-date
git pull
git switch -c feature/squash-practice
```

### 2. Adding Code Slowly
Create a file called `math_tools.py` (or `.js`):
1. Write a function the messy way, adding a file:
```python
def add(a, b):
    return a - b
```
Commit it: 
```
git add .
git commit -m "WIP math"
```

2. Oh wait! That contains a bug! Fix the `-` to `+`.
```python
def add(a, b):
    return a + b
```
Commit it: `git commit -am "fix math typo omg"`

3. Wow, we forgot a subtract function! Add it.
```python
def sub(a, b):
    return a - b
```
Commit it: `git commit -am "added subtract"`

### 3. Viewing the Mess
Use `git log --oneline` feature/squash-practice to view your branch history.
You have 3 terrible, tiny commits. We want to convert them into a single, clean commit titled: `"feat: add core math algorithms"`.

### 4. Interactive Rebase
We need to group our last 3 commits! Run:
```bash
git rebase -i HEAD~3
```
Your default text editor (usually Vim or Nano in the terminal) will open a scary file showing your three commits with the word `pick` in front of them:

```text
pick 1a2b3c4 WIP math
pick 5d6e7f8 fix math typo omg
pick 9g0h1i2 added subtract
```

### 5. Squashing!
We want to keep the top one (the base), and "squash" the next two into it. Change the word `pick` to `squash` (or `s`) for the second and third commits:

```text
pick 1a2b3c4 WIP math
squash 5d6e7f8 fix math typo omg
squash 9g0h1i2 added subtract
```

Save the file and close the editor (if in vim, type `:wq` and Enter). 

Git will immediately open another editor window, asking you to construct a combined commit message. Delete or comment out the old messy messages, and write:
```text
feat: add core math algorithms
```
Save and close this file.

### 6. The Reveal
Run `git log --oneline` again. Your messy history is gone, replaced with a single, professional commit.

### 7. Push and Open a Pull Request
Push your clean squashed branch to your fork:
```bash
git push -u origin feature/squash-practice
```

> **If you pushed earlier commits before squashing:** Squashing rewrites history (the commit hash changes), so GitHub will reject a standard push because your local and remote histories no longer match. Use a **force push** instead:
> ```bash
> git push origin feature/squash-practice --force
> ```
> This is safe here because you are the only one working on this branch.

Go to GitHub and open a Pull Request:
- **base repository**: the original upstream repo
- **base**: `main`
- **compare**: `feature/squash-practice`

Notice that your PR shows exactly **one** clean, descriptive commit instead of three messy ones — this is exactly what open-source maintainers love to see.

Click **"Create pull request"**. ✅

➡️ **Next Up:** [Module 5: Time Travel](./05-TIME-TRAVEL.md)
