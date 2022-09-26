1. ssh

- Change port:
```
nano /etc/ssh/sshd_config
Port 22000
systemctl restart sshd
netstat -tulpn | grep ssh
ssh -p 22000 192.168.1.100
```

- Alias
```
cat ~/.ssh/config 
Host name
    HostName abc.abc.abc.abc
    User root
    Port 22
```


2. nginx
```
sudo nano /etc/nginx/sites-available/default
  server {
      listen 80;
      server_name abc.com;

      location / {
              proxy_set_header Host $host;
              proxy_pass http://127.0.0.1:5000;
              proxy_redirect off;
      }
  }
```
```
  sudo nano /etc/nginx/nginx.conf
  client_max_body_size 100M;
```


3. ufw
```
sudo nano /etc/default/ufw
IPV6=yes

sudo ufw default deny incoming
sudo ufw default allow outgoing

sudo ufw allow ssh
ufw allow 'Nginx HTTP'

sudo ufw logging on
sudo ufw status

sudo ufw allow ...
sudo ufw status numbered
sudo ufw delete 3
sudo ufw delete allow 22/tcp
sudo ufw allow 1234/tcp
sudo ufw status verbose
sudo ufw reload
```


4. nvm
```
curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash
source ~/.bashrc
nvm install 16.17.1
```


5. docker
```
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu `lsb_release -cs` test"
sudo apt update
sudo apt install docker-ce

sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```


6. Visual Studio Code
```
sudo apt update && sudo apt upgrade -y
sudo apt install software-properties-common apt-transport-https wget
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
sudo apt install code
```


7. Google Chrome
```
wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
echo 'deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main' | sudo tee /etc/apt/sources.list.d/google-chrome.list
sudo apt-get update 
sudo apt-get install google-chrome-stable
```


8. scp
```
scp -P 2212 public/uploads.zip root@159.223.64.220:
scp user@server:/path/to/remotefile.zip /Local/Target/Destination
```
