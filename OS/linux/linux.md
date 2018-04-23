0. **Short cut**
   
   a. **Terminal**
   
   `Ctrl + Alt + T`
   
   b. **Show desktop**
   
   `Ctrl + (Super)Windows + D`

1. **Remove all file in directory**
```
rm -rf *
```

2. **Remove all file in directory but not**
```
rm -rf *[^demo]*
```

3. **Install VietNamese**
```
sudo apt-get install ibus-unikey

ibus restart
```

4. **Can't mount partion**
```
Access windows system -> power option -> turn off fast startup -> restart computer.
```

5. **Install PhpStorm**

`cd PhpStorm-143.1184.87/bin/`

`./phpstorm.sh`

6. **Update grub**

`sudo update-grub`

7. ** Free space**

`sudo du -sh *`

8. **Ip v4**

`hoanki@hoanki-HP-EliteBook-8470p:~$ sudo chmod 777  /etc/apt/apt.conf.d
hoanki@hoanki-HP-EliteBook-8470p:~$ sudo touch "Acquire::ForceIPv4 "true"; " >> /etc/apt/apt.conf.d/99force-ipv4`

9. **Error update**

```
$ sudo -i
# apt-get clean
# cd /var/lib/apt
# mv lists lists.old
# mkdir -p lists/partial
# apt-get clean
# apt-get update
```

