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

Git will automatically generate a new commit called `Revert "fix: improved server security by disabling connections"`. This doesn't permanently delete the bad commit from history. It writes down the correction moving forward. This is the safest way to fix open-source PR mistakes!

### 4. Hard Reset (Going Back in Time Unsafely)
Sometimes, you haven't published your code yet, and you just want to obliterate a commit completely from your local history.

Make *another* terrible commit to `server.txt`:
```text
Port: NaN
```
Commit it: `git commit -am "feat: made ports infinite"`

Now, instead of reverting it, let's rewind time using a **Hard Reset**. First, figure out where you *want* to be, using your commit log:
```bash
git log --oneline
```
Find the ID of the commit BEFORE your terrible infinity port commit. Then run:

```bash
git reset --hard <safe-commit-hash>
```
Your local files will immediately reset. The bad commit is permanently erased from your timeline! 

➡️ **Next Up:** [Module 6: Stashing & Ignoring](./06-STASHING-AND-IGNORE.md)
