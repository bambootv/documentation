Config to run Yii2 application in Centos 7
==============================

### Problem: SElinux is enabled
* httpd process don't have permission to write
* user in group `apache` can write in some folder

### 5 steps
1. Config folder web app with 754 permission

`chmod -R 754 <path/to/web/directory>`

2. Add user to group `apache`

`usermod <username> -gapache`

3. Config webapp owner and apache group

`chown -R <username>:apache <path/to/web/directory>`

4. Enable writeable for httpd process to some folder

Example: `runtime/`, `web/assets/`

`chcon -R -t httpd_sys_content_rw_t runtime/ web/assets`

5. Enable writeable some folder for user in group apache

`chmod -R 774 runtime/ web/assets`


