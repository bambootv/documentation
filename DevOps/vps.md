1. SSH

- On local:
```
ls -l ~/.ssh/id*
mkdir ~/.ssh
chmod 700 ~/.ssh
ssh-keygen
   /home/<username>/.ssh/id_rsa_<server_name>
ls -l ~/.ssh/
cat /home/<username>/.ssh/id_rsa_<server_name>.pub

nano ~/.ssh/config
Host <alias_name>
    HostName xxx.xxx.xx.xxx
    User <username>
    Port xxx
ssh <alias_name>
```


- On server:
```
# Change port:
nano /etc/ssh/sshd_config
Port 123456
systemctl restart sshd
netstat -tulpn | grep ssh
ssh -p 123456 192.168.1.100

# Disable login with password for all accout
PasswordAuthentication no
nano /etc/ssh/sshd_config.d/50-cloud-init.conf  # It will mix with ssh/sshd_config
If see PasswordAuthentication yes, set it to no

If not working, read more about 
ChallengeResponseAuthentication no

#Login with key:
sudo useradd -m -s /usr/bin/zsh <username>
sudo passwd <username>
ls -l ~/.ssh/
mkdir ~/.ssh
chmod 700 ~/.ssh
touch authorized_keys
chmod 600 ~/.ssh/authorized_keys
nano ~/.ssh/authorized_keys
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
```
sudo rm /var/log/nginx/access.log
sudo service nginx reload
sudo truncate --size 0 /var/log/nginx/access.log
```

3. ufw
```
sudo nano /etc/default/ufw
IPV6=yes

sudo ufw default deny incoming
sudo ufw default allow outgoing

sudo ufw allow ssh
ufw allow 'Nginx HTTP'
sudo ufw allow 1234/tcp

sudo ufw logging on

sudo ufw status
sudo ufw status numbered
sudo ufw delete 3
sudo ufw delete allow 22/tcp

sudo ufw status verbose (list)
sudo ufw reload

SSH
sudo ufw allow 'Nginx Full'
sudo ufw delete allow 'Nginx HTTP'
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
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "2m",
    "max-file": "3"
  }
}
sudo service docker restart
sudo systemctl stop docker.socket // If can not restart and restart again

[sudo permission ](https://docs.docker.com/engine/install/linux-postinstall/#manage-docker-as-a-non-root-user)
```


5. scp
```
scp -P 2290 public/uploads.zip root@159.223.64.220:
scp user@server:/path/to/remotefile.zip /Local/Target/Destination
```

6. npm
```
apt install npm
```

7. git 

``` 
Multi ssh for diffrent project
ssh-keygen -t rsa -b 4096 -C "bamboo@gmail.com"
/root/.ssh/id_rsa_<app_name>
cat ~/.ssh/id_rsa_<app_name>.pub 

nano ~/.ssh/config
Host github.com_<app_name>
	HostName github.com
	User git
	IdentityFile ~/.ssh/id_rsa_<app_name>

git clone git@github.com_<app_name>:xxx/xxx.git
```

8. SSL

```
certbot certonly \
  --dns-cloudflare \
  --dns-cloudflare-credentials ~/.secrets/certbot/cloudflare.ini \
  -d abc.com \
  -d *.abc.com

cat ~/.secrets/certbot/cloudflare.ini
# Cloudflare API token used by Certbot
dns_cloudflare_api_token = cewqd2sqxsxs

sudo certbot renew --dry-run

sudo certbot renew --reuse-key --dry-run

ls -la /etc/letsencrypt/live/abc.com
```
