# Module 5: Time Travel

One of Git's superpowers is fearlessness: you can mess up without permanent consequences because you can always go backward in time.

## Task Objective

We are going to learn how to travel backward through history safely (Reverting) and unsafely (Resetting). You will deliberately introduce a bad commit, find the author with `git blame`, and revert it.

## Walkthrough

### 1. The Setup (Creating Bad Code)
We need a file to ruin. Start from `main` and branch out:
```bash
git switch main
git switch -c feature/time-travel
```
Create `server.txt` and add this text:
```text
Port: 8080
Connections: Allowed
```
Commit it: 
```bash
git add .
git commit -m "chore: created server config"
```

Now... let's introduce a terrible mistake! Change `Connections: Allowed` to `Connections: Disabled`.
Commit it: `git commit -am "fix: improved server security by disabling connections"`

### 2. Hunting Down the Mistake
Someone complains that the server is broken. We need to figure out which commit broke it, and who made it!

Run `git blame server.txt`
This shows you, line-by-line, the commit hash and author that last edited each line! Find the exact commit hash that introduced `Connections: Disabled`.

Copy that commit hash (the 7-character code at the beginning of the line).

### 3. Reverting the Mistake Safely
Instead of manually deleting the bad line, we use Git to "undo" the bad commit. A revert essentially creates a *new* commit that is diametrically opposite to the bad one.

Run:
```bash
git revert <bad-commit-hash>
```

Git will open your default text editor to write a commit message. It pre-fills it with `Revert "fix: improved server security by disabling connections"`. Save and close the editor to confirm. This creates a **new** commit that undoes the bad one — the bad commit stays in history (for auditability), but its effects are cancelled out. This is the safest way to fix open-source PR mistakes.

### 4. Push Your Branch and Open a Pull Request
Your branch now tells a complete, honest story: the original config was created, a bad change was introduced, and a revert commit safely undid it.

Push the branch to your fork:
```bash
git push -u origin feature/time-travel
```
Go to GitHub and open a Pull Request:
- **base repository**: the original upstream repo
- **base**: `main`
- **compare**: `feature/time-travel`

In your PR description, note: *"Used `git revert` to safely undo a bad commit while preserving full history."*

Click **"Create pull request"**. ✅

---

## 💡 Bonus Concept: Hard Reset (Dangerous, Local Only)

Sometimes you haven't pushed your code yet and you want to completely erase a bad commit from your local history — as if it never happened. This is a **destructive** operation. It is safe only when the commits have **not** been pushed to any remote.

### 5. Hard Reset (Going Back in Time Unsafely)
Make *another* terrible commit to `server.txt`. Change the Port line:
```text
Port: NaN
```
Commit it: `git commit -am "feat: made ports infinite"`

Now, instead of reverting, let's rewind time. First, find the commit you want to go back to:
```bash
git log --oneline
```
Find the hash of the commit **before** your "infinite port" commit (the revert commit from step 3). Then reset to it:

```bash
git reset --hard <safe-commit-hash>
```
Your local files reset instantly. The bad commit is permanently erased from your local timeline.

> **Warning:** Never use `git reset --hard` on commits you have already pushed to a shared remote. It rewrites history and will cause problems for everyone else working on that branch. Use `git revert` instead (as you did in step 3) when history is already public.

➡️ **Next Up:** [Module 6: Stashing & Ignoring](./06-STASHING-AND-IGNORE.md)
