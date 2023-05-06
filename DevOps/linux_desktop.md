
1. Google Chrome
```
wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
echo 'deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main' | sudo tee /etc/apt/sources.list.d/google-chrome.list
sudo apt-get update 
sudo apt-get install google-chrome-stable
```

2. [Zsh](https://viblo.asia/p/cai-oh-my-zsh-powerlevel10k-toi-uu-va-su-dung-phim-tat-cho-terminal-ORNZqowM50n#_4-tim-hieu-zsh-8)
```
sudo apt-get install zsh
chsh -s $(which zsh)
logout

cd
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

 [zsh-autosuggestions](https://github.com/zsh-users/zsh-autosuggestions#installation)
```
nano ~/.zshrc
plugins=(git zsh-autosuggestions)
```

![Screenshot from 2023-05-06 15-57-02](https://user-images.githubusercontent.com/18675907/236614202-4d356ae2-20d8-40b6-865a-a697e0e3e697.png)



3. Ibus
```
sudo apt-get install ibus-unikey
ibus restart
```

4. nvm
```
curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash
source ~/.szhrc
nvm install 16.18.0
```

5. Visual Studio Code
```
sudo apt update && sudo apt upgrade -y
sudo apt install software-properties-common apt-transport-https wget
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
sudo apt install code
```

6. alia ssh
```
cat ~/.ssh/config 
Host name
    HostName abc.abc.abc.abc
    User root
    Port 22
```

7. zip
```
zip -r images.zip images/
```
