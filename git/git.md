Help for Git
============


1. Install on Linux

`sudo apt-get install git-all`

if error

`sudo apt-get purge runit`

`sudo apt-get purge git-all`

`sudo apt-get purge git`

`sudo apt-get autoremove`

`sudo apt update`

`sudo apt install git`


2. Delete n last commit

`git reset HEAD~n`

`git push -f origin master`


3. User and email

`git config --global user.name "Your Name"`

`git config --global user.email "youremail@domain.com"`


4. Remember password

`use SSH Key`


5. Show graph

Graph: `git log --graph --oneline`

Online: `git log --online`

6. Gộp n commit thành 1 commit

`git rebase -i HEAD~n`

Thay những chữ `pick` cuối cùng bằng `f` 

7. Delete branch

Local:
`git branch -d <branch_name>`

Remote:
`git push origin --delete <branch_name>`

8. Khôi phục bằng reflog 

Xem lịch sử `git reflog`
 
Quay lại sau khi "nhỡ tay": `git reset --hard HEAD~ <id of commit>`


