**1. Show process**

``
pgrep -l -u hoanki
``

**2. Kiss process**

``
kiss -9 [process-id]
``

**2. Which process is using port ?**
```
netstat -ltnp | grep -w ':6379' 
sudo apt install net-tools
```
