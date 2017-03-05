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


`git config --global credential.helper cache`

`git config --global credential.helper 'cache --timeout=3600'`


