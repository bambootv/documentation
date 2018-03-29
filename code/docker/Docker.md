```
-f: Runing
-a: Turned off container
-d: Only show ID
```

**Images**

1. **Listed images**
```
sudo docker images
```

2. **Pull image**
```
sudo docker pull Author/Images name
```

3. **Remove all image**
```
sudo docker rmi -f $(sudo docker images)
```

4. **Remove all none image**
```
sudo docker rmi -f $(sudo docker images -f "dangling=true" -q)
```

5. **Build image**
```
sudo docker build Author/Images name
```

**Container**
```
/bin/bash: Access command line mode off container
-t: Create terminal fake in container
-i: Interactive through STDIN standard of container
```

1. **Listed container**
```
sudo docker ps -a -q
```

2. **Run container from images**
```
sudo docker run -v <forder in computer>:<forder in container> -p <port in computer>:<port in container> -it <image name> /bin/bash
```

3. **Remove all containers**
```
sudo docker rm -f $(docker ps -a -q)
```

4. **Access container**
```
sudo docker exec -it ID bash
```
