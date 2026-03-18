1. Fork and clone the forked repo to your local machine
```bash
gh repo fork OWNER/REPO --clone --remote
cd cli
```
2. Create and switch to a new branch 
```bash
git checkout -b my-feature-branch
```
3. Make your changes locally
4. Stage and commit
```bash
git add .
git commit -m "commit"
git push -u origin my-feature-branch
```
5. Open a pull request
```bash
gh pr create --fill
```
6. Respond to feedback and update PR
7. Update as much as possible
```bash
gh repo sync OWNER/FORKED_REPO -b main
```