# Module 8: The PR Review Lifecycle

In the real world, a Pull Request is almost never approved on the first try. A senior developer or maintainer will review your code, point out issues, and request changes. 

## Task Objective

Learn the workflow of addressing PR feedback: making changes to an already open PR, linking issues, and force-pushing clean history.

## Walkthrough

### 1. The Scenario
Imagine you opened a PR for a new feature. You linked it to the issue you were working on by typing `Closes #42` in your PR description on GitHub (this automatically closes the issue when your PR merges!).

However, the maintainer reviewed your PR and said: *"Looks good, but please rename `data_fetcher` to `fetchData` for consistency."*

### 2. Updating Without Opening a New PR
Many beginners panic, close their PR, make the changes, and open a brand new PR. **Don't do this!** A PR automatically tracks the branch it came from. 

All you need to do is push new commits to the **exact same branch**.

Ensure you are on the branch you created the PR from:
```bash
git switch feature/my-awesome-feature
```

### 3. Make the Changes
Rename your variable as requested in the code.

### 4. Two Ways to Update

**Way A: The "Just Add " Commit (Easy, but messy)**
You can just add a new commit and push it up.
```bash
git add .
git commit -m "addressing PR review: rename variable"
git push origin feature/my-awesome-feature
```
The PR will instantly update on GitHub with your new commit! This is fine, but maintainers often prefer a clean history.

**Way B: Amending (Clean and Professional)**
Instead of adding a new "fix review" commit, let's just slide the changes into your *previous* commit.

```bash
# Add your changes
git add .

# Sneak them into the last commit, skipping the editor
git commit --amend --no-edit
```
Now, because you altered history (the hash of your commit changed), Git will reject a standard push because your local history doesn't match GitHub's history. You must **force push**.

```bash
git push origin feature/my-awesome-feature --force
# or git push -f
```

The PR updates automatically, the maintainer sees the pristine code, and merges it!

---

🎉 **You made it to the end of the Git Training Repository!** 🎉

By mastering these 8 modules, you now have the tools required to survive—and thrive—in real-world Open Source and Enterprise engineering workflows! Go conquer that codebase!