1. Code
```
'use strict';

const axios = require('axios');
const range = require('range');
const moment = require('moment');
const knex = require('@config/database');

const { Currency } = require('@models');
const { currency } = require('@config/currency');

module.exports = {
    name: 'system',
    actions: {
        getCurrency: {
            visibility: 'published',
            async handler() {
                const CURRENCIES = currency.type;

                let paths = await Currency.query().count()
                    .then(async res => {
                        let results = [];
                        if (res[0].count !== '0') {
                            // Only get from yesterday
                            CURRENCIES.forEach(fromCurrency => {
                                CURRENCIES.forEach(toCurrency => {
                                    if (fromCurrency !== toCurrency) {
                                        let date = moment().subtract(1, 'days').format('YYYY-MM-DD');
                                        let path = `timeseries?start_date=${date}&end_date=${date}&base=${fromCurrency}&symbols=${toCurrency}`;
                                        results.push(path);
                                    }
                                });
                            });
                        } else {
                            // Get from 2 years ago
                            await knex.raw('truncate currencies restart identity');
                            const currentYear = new Date().getFullYear();
                            const YEARS = range.range(currentYear - 1, currentYear + 1);
                            CURRENCIES.forEach(fromCurrency => {
                                CURRENCIES.forEach(toCurrency => {
                                    if (fromCurrency !== toCurrency) {
                                        YEARS.forEach(year => {
                                            // // Use this block
                                            // let startDate = `${year}-01-01`;
                                            // let endDate = '';

                                            // if (year === currentYear) {
                                            //     endDate = moment().subtract(1, 'days').format('YYYY-MM-DD');
                                            // } else {
                                            //     endDate = moment(startDate).endOf('year').format('YYYY-MM-DD');
                                            // }

                                            // Comment this block
                                            let date = moment().subtract(2, 'days').format('YYYY-MM-DD');
                                            let startDate = date;
                                            let endDate = date;

                                            let path = `timeseries?start_date=${startDate}&end_date=${endDate}&base=${fromCurrency}&symbols=${toCurrency}`;
                                            results.push(path);
                                        });
                                    }
                                });
                            });
                        }
                        return results;
                    });

                let currencyRate = [];
                let requests = paths.map(path => (
                    axios.get(`https://api.exchangerate.host/${path}`)
                        .then(res => {
                            let rates = res.data.rates;
                            let baseCurrency = res.data.base;
                            this.logger.info('Getting currency rate with', path);

                            Object.keys(rates).forEach(key => {
                                let object = rates[key];
                                currencyRate.push({
                                    day: key,
                                    from: baseCurrency,
                                    to: Object.keys(object)[0],
                                    value: Object.values(object)[0]
                                });
                            });
                        })
                        .catch(err => {
                            this.logger.error(err);
                            throw err;
                        })
                ));
                await Promise.all(requests);
                return Currency.query()
                    .insert(currencyRate)
                    .onConflict(['from', 'to', 'day']).ignore()
                    .then(() => {
                        return {
                            success: true
                        };
                    });
            }
        }
    }
};

```
