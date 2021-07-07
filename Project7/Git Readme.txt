git init --> For initing new git repos  
git status --> To view the status of repo
git add <file_name>--> To make file staged (move it to index)
git add . --> This means (.) All files (except .gitignore)
git commit -m "Commit massage" --> Moving files from index to archive
git commit -am "Coommit massage" --> To add and commit at same time(Only for modified, it doesn't work with new files)
git remote add origin https://github.com/someGitAcc/someGitReps.git --> To connect your repo to GitHub
git remote -v --> To see any remote repositories connected to this repo
git push -u origin <brench_name> --> To push your commits to remote repo
git push -u origin master --> To set the default location of pushing(After that you can type just git push)
git config --global user.name <your_username> --> To see or enter the new Username
git config --global user.email <your_email> --> To see or enter the new email
git branch <branch_name> --> To see or add new branch in your repo
git branch -d <branch_name> --> To delete the branch
git checkout <branch_name> --> To change your current branch
git checkout -b <brenc_name> --> To make new branch
git clone <https://github.com....> --> Clone this repo to current directory
git pull origin <branch>--> To Download changes from remote repo to local machine
git diff <branch_name> --> Showing differencies between that branch and current branch 
git merge <branch_name> --> Merging current and selected branches
git reset <file_name> --> Unstaging the file (Deleting from index, opposite of add)
git push origin :<branch_name> --> Removing branch remotely
git log --> Showing logs
git reset HEAD~<x> --> Reseting last x commits
git reset <HASH OF COMMIT> --> Reseting git to the point of commit hash
git reset --hard <HASH OF COMMIT> --> Reseting git and the files to the point of commit hash
rm -rf .git --> To localy delete your git repo
---------------Conflicts during merge ---------------------
For example there is some index.html, in 9th line in master branch there is <hello> in feautre branch there is <morning>
To solve the conflict you must choose between them.
If you want choose the master 
	git checkout --ours <file_name>
if you want to choose the feautre 
	git checkout --theirs <file_name>
(if you are in master branch)
 if you want to see the both variants type
	git checkout --merge <file_name>
OR if you want to see base variant also type
	git checkout --conflict=diff3 --merge <file_name>
if there is something wrong and you want to cancel the merging type
	git reset --merge
	or git reset --hard (this might harm files, which are added but not commited)
