
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

git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions

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
ibus-daemon -d
ibus restart
```


4. docker
```
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu `lsb_release -cs` test"
sudo apt update
sudo apt install docker-ce

COMPOSE_VERSION=$(curl -s https://api.github.com/repos/docker/compose/releases/latest | grep 'tag_name' | cut -d\" -f4)
sudo curl -L "https://github.com/docker/compose/releases/download/${COMPOSE_VERSION}/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose

mkdir /etc/docker
sudo nano /etc/docker/daemon.json
{
  "log-driver": "json-file", # none
  "log-opts": {
    "max-size": "1m",
    "max-file": "3"
  }
}
sudo service docker restart
sudo systemctl stop docker.socket // If can not restart and restart again
```

[Manage Docker as a non-root user](https://docs.docker.com/engine/install/linux-postinstall)
```
sudo groupadd docker
sudo usermod -aG docker $USER
logout
newgrp docker
sudo chmod 666 /var/run/docker.sock
```


5. nvm
```
curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash
source ~/.szhrc
nvm install 16.18.0
nvm use 16.18.0
nvm alias default 16.18.0
```

6. Visual Studio Code
```
sudo apt update && sudo apt upgrade -y
sudo apt install software-properties-common apt-transport-https wget
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
sudo apt install code
```

7. alia ssh
```
cat ~/.ssh/config 
Host name
    HostName abc.abc.abc.abc
    User root
    Port 22
```

8. zip
```
zip -r images.zip images/
```

9. Prevent adult conent

[CleanBrowsing](https://cleanbrowsing.org/help/docs/configure-dns-filtering-on-linux/)
```
sudo nano /etc/resolv.conf
nameserver 185.228.168.168
sudo chattr +i /etc/resolv.conf
```

10. IP
```
ip route
... 192.168.xxx.xxx 
# Can use it to DNS (CloudFlare, ...) but is is flexiable
# Can buy static ip from provider
```

11. Check size
```
tree --du -h
du -sh ./*
```

12. Redis
```
redis-cli
> AUTH YourPasswordHere
```
