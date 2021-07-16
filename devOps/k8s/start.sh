#!/bin/bash

# service nginx start
service mysql start
nginx -g 'daemon off;'

exec $@
