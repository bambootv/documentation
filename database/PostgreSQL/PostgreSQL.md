1. Update multi row

```SQL
update public.users as row set
    first_name = data.first_name,
    last_name = data.last_name,
    detail = data.detail
from (values
    (1, 'A', 'B', '{"locales":"HN"}'::jsonb),
    (2, 'C', 'D', '{"locales":"HN"}'::jsonb),
    (3, 'E', 'F', '{"locales":"HN"}'::jsonb)
) as data(id, first_name, last_name, detail)
where data.id = row.id
```

```javascript
let updateData = '';
payload.forEach(el => {
    el.detail = el.detail.replace(/'/g, '');
    updateData += `('${el.id}','${JSON.stringify(el.detail)}'::jsonb),`;
});
if(updateData.length > 0){
    return knex.raw(`
        update public.ad_accounts as row set
        detail = data.detail
        from (values ${updateData.slice(0, -1)})
        as data(id, detail)
        where data.id = row.id
    `);
}
```

```javascript
let updateData = '';
payload.forEach(el => {
    updateData += `('${el.id}','${JSON.stringify(el.detail)}'::jsonb),`;
});
if(updateData.length > 0){
    return knex.raw(`
        update public.ad_accounts as row set
        detail = data.detail
        from (values ?)
        as data(id, detail)
        where data.id = row.id
    `, updateData.slice(0, -1));
}
```

2. Search without accent
Note: Need permission
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

4. Update validate enum
```
exports.up = (knex) => {
    return knex.schema.raw(`
        ALTER TABLE "coupons"
        DROP CONSTRAINT "coupons_type_check",
        ADD CONSTRAINT "coupons_type_check"
        CHECK (type IN ('percentage', 'flat'))
    `);
};
```

5. Joins
```
publishable(userId) {
        return this.leftJoin('drafts', function condition() {
            this.on('drafts.object_id', '=', 'campaigns.id');
        })
            .where(function findbyCamStatus() {
                this.whereNotIn('campaigns.sync_status', ['need_publish', 'publishing']) // change way to see with notIn
                    .orWhere(function findbyDraftStatus() {
                        this.where('campaigns.sync_status', '=', 'active')
                            .where('drafts.object_type', '=', 'campaign')
                            .where('drafts.user_id', '=', userId)
                            .whereNotIn('drafts.sync_status', ['need_publish', 'publishing', 'need_update', 'updating']);
                    });
            });
    }
```

where ở ngoài thì leftjoin b

```
.leftJoin('drafts', 'drafts.object_id', '=', 'campaigns.id')
                .where('drafts.object_type', '=', 'campaign')
                .where('drafts.user_id', '=', ctx.meta.user.id);
            // .leftJoin('request_details', function complexJoin() {
            //     this.on(
            //         'request_details.object_id', '=', 'campaigns.id'
            //     ).andOn(
            //         'request_details.object_type', '=', this.knex().raw('?', ['campaign'])
            //     ).andOn(
            //         'request_details.status', '=', this.knex().raw('?', ['waiting'])
            //     );
            // });
```

6. Where `unaccent`
```
query.where(function name() {
                        this.where(knex.raw('unaccent(facebook_name)'), 'ilike', knex.raw(`unaccent('%${ctx.params.keyword}%')`))
                            .orWhere(knex.raw('facebook_campaign_id::TEXT'), 'ilike', `%${ctx.params.keyword}%`);
                    });
```

7. Check_type
```
tale: constraint_column_usage
```

8. CASE WHEN
```
.select(['ads.*'].concat([
    'drafts.content as draft',
    knex.raw('CASE WHEN request_details.id > 0 THEN true ELSE false END AS in_request')
]));
```
