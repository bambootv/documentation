**Remove none:none image**

```
docker rmi -f $(docker images -f "dangling=true" -q)
```

**Remove all containers**
```
docker rm $(docker ps -a -q)
```

**View structure container**
```
docker exec -it ID bash
```

