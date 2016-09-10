```
-f: Runing
-a: Turned off container
-d: Only show ID
```

**Images**

1. **Listed images**
```
docker images
```

2. **Pull image**
```
docker pull Author/Images name
```

3. **Remove all image**
```
docker rmi -f $(docker images)
```

4. **Remove all none image**
```
docker rmi -f $(docker images -f "dangling=true" -q)
```

5. **Build image**
```
docker build Author/Images name
```

**Container**
```
/bin/bash: Access command line mode off container
-t: Create terminal fake in container
-i: Interactive through STDIN standard of container
```

1. **Listed container**
```
docker ps -a -q
```

2. **Run container from images**
```
docker run -v <forder in computer>:<forder in container> -p <port in computer>:<port in container> -it <image name> /bin/bash
```

3. **Remove all containers**
```
docker rm -f $(docker ps -a -q)
```

4. **Access container**
```
docker exec -it ID bash
```