**View images**
```
docker images
```

**Remove none:none image**
```
docker rmi -f $(docker images -f "dangling=true" -q)
```

**Remove none:none image**
```
docker rmi -f $(docker images)
```

**View container**
```
docker ps -a -q
```

**Remove all containers**
```
docker rm -f $(docker ps -a -q)
```

**View structure container**
```
docker exec -it ID bash
```



