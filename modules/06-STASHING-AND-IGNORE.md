# Module 6: Stashing & Ignoring

You will inevitably generate files you don't *want* Git to track (like private environment variables). You will also inadvertently be halfway through coding a feature when a teammate asks for an urgent hotfix, forcing you to switch branches mid-work without wanting to commit broken code.

## Task Objective

We are going to learn how to ignore a file globally using `.gitignore`. Then, we will create "dirty" uncommitted work, stash it away so we can switch contexts, and magically pop it back into existence later.

## Walkthrough

### Part 1: Ignoring Secrets

#### 1. Oh no, a secret key!
When working on web applications, we often store passwords in `.env` files. We absolutely never want to commit these. 

Switch to a fresh branch:
```bash
git switch main
git switch -c fix/ignore-secrets
```

Create a file named `.env` and put a fake API key inside it:
```text
STRIPE_API_KEY=sk_test_123456789
```

If you run `git status`, Git warns you there is an untracked `.env` file. Do not commit this!

#### 2. Using .gitignore
Create another file in the root folder, simply called `.gitignore`. It has no prefix/name, just the `.gitignore` extension.
Inside it, type the names of files or folders you want git to permanently pretend don't exist:
```text
.env
```
Save the file. Now run `git status`. Notice how `.env` vanished from the list of tracked items? Now you can safely commit your `.gitignore`.
```bash
git add .gitignore
git commit -m "chore: add gitignore for environment variables"
```

---

### Part 2: Stashing Half-Baked Code

#### 3. Halfway Done with a File
Let's pretend we are adding `node_modules` folder to `.gitignore` so that it is not pushed.
Open the file called `.gitignore` and start adding code below the line containing `.env`:
```text
node_
```

We aren't done. We still need to add `modules`, but... **🚨 EMERGENCY! 🚨** You must switch back to `main` instantly to fix a production bug. You can't switch branches because Git warns you that you have uncommitted changes. You don't want to make an ugly `WIP` commit.

#### 4. The Magic of Stashing

Tell Git to sweep your current uncommitted changes into a temporary box.
```bash
git stash
```
Run `git status`. Your working directory is completely clean! Look at your files. `node_` is missing from the `.gitignore` file ! Where did it go?

#### 5. Fixing the Bug
Now you're free to switch branches!
```bash
git switch main
```
You can pretend to do some critical fix here. When you are done, jump back to your feature.
```bash
git switch fix/ignore-secrets
```

#### 6. Popping the Stash
To get your half-baked code back, you just tell Git to open the box!
```bash
git stash pop
```
`node_` is instantly restored, exactly in the half-done state you left it. Now you can finish adding node_modules to gitignore, add `modules`, and finally commit!

After commiting, move on to the next step

➡️ **Next Up:** [Module 7: Syncing Your Fork](./07-SYNCING-FORKS.md)
