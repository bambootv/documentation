1. List foreign of table

```sql
select  * from information_schema.key_column_usage where constraint_catalog=current_catalog and table_name='facebook_relationships' and position_in_unique_constraint notnull;
```
