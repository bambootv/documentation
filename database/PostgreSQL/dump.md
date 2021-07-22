[Docs](https://www.postgresql.org/docs/13/app-pg-dumpall.html)

1. Backup

```bash
pg_dumpall > db.out
pg_dumpall -h postgresql.default -U postgres -f /backup/postgres/backup"$(date +%Y.%m.%d-%H.%M.%S)".tar
```

2. Restore

```bash
psql -f db.out postgres
# It is not important to which database you connect here since the script file created by pg_dumpall will contain the appropriate commands to create and connect to the saved databases. An exception is that if you specified --clean, you must connect to the postgres database initially; the script will attempt to drop other databases immediately, and that will fail for the database you are connected to.
```
