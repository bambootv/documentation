1. Update multi row

```SQL
update public.users as row set
    first_name = data.first_name,
    last_name = data.last_name
from (values
    (1, 'A', 'B'),
    (2, 'C', 'D'),
    (3, 'E', 'F')
) as data(id, first_name, last_name)
where data.id = row.id
```

2. Search without accent
```SQL
CREATE EXTENSION IF NOT EXISTS unaccent;

SELECT *
FROM "campaigns"
WHERE  unaccent(facebook_name) ILIKE unaccent('Chien dịch moi');
```

3. Truncate table
```
truncate ad_accounts RESTART IDENTITY CASCADE
```
