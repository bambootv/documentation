1. url
```javascript
const request = new bizSdk.APIRequest(null, 'GET', `/${ctx.params.facebook_ad_account_id}/generatepreviews`)
  .addFields(['body'])
  .addParams({
      ad_format: adFormat,
      access_token: ctx.params.access_token,
      creative: encodeURIComponent(JSON.stringify(ctx.params.creative))
  });
```
