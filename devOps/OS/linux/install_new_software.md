1. `Google chrome:`

* wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add - 
* sudo sh -c 'echo "deb http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google.list'
* sudo apt-get update 
* sudo apt-get install google-chrome-stable 

2. `Team Viewer:`

* sudo su -c "echo 'deb http://sparkylinux.org/repo testing main' >> /etc/apt/sources.list"
* sudo apt-get update
* sudo apt-get install teamviewer
