[Docs](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)
[Docs](https://gist.github.com/jexchan/2351996)

1. **Multi ssh for diffrent project**
```
ssh-keygen -t rsa -b 4096 -C "bamboo@gmail.com"
/root/.ssh/id_rsa_<app_name>
cat ~/.ssh/id_rsa_<app_name>.pub 

nano ~/.ssh/config
Host github.com-<app_name>
	HostName github.com
	User git
	IdentityFile ~/.ssh/id_rsa_<app_name>

git clone git@github.com-<app_name>:xxx/xxx.git

```
