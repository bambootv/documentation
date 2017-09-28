**1. Install xampp**

``chmod +x xampp-linux-5.6.3-0-installer.run``


``sudo ./xampp-linux-5.6.3-0-installer.run``

``sudo /opt/lampp/lampp restart``


Start server

``sudo /opt/lampp/lampp start``



If start server error

`` sudo /etc/init.d/apache2 stop``

``sudo service apache2 stop``

``sudo service mysql stop``

``sudo /opt/lampp/lampp start``

**2. Install composer**

`` sudo apt-get install php  ``

`` sudo php -v ``

`` php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"``

``php -r "if (hash_file('SHA384', 'composer-setup.php') === '669656bab3166a7aff8a7506b8cb2d1c292f042046c5a994c43155c0be6190fa0355160742ab2e1c88d40d5be660b410') { echo 'Installer verified'; } else { echo 'Installer corrupt'; unlink('composer-setup.php'); } echo PHP_EOL;"``

``php composer-setup.php``

``php -r "unlink('composer-setup.php');"``


**2. Config**

``/opt/lampp/etc/extra``

`` <VirtualHost kyuujin-front.local:80>``
      ``ServerAdmin webmaster@dummy-host2.example.com``
      ``DocumentRoot "/opt/lampp/htdocs/kyuujin-front"``
      ``ServerName kyuujin-front.local`` 
      ``ErrorLog "logs/dummy-host2.example.com-error_log"``
      ``CustomLog "logs/dummy-host2.example.com-access_log" common``
      ```<Directory "/opt/lampp/htdocs/kyuujin-front">```
          ``Options FollowSymLinks``
          ``AllowOverride All``
          ``DirectoryIndex index.php``
          ``Require all granted``
      ``</Directory>``
  ``</VirtualHost>``
  
  ``/opt/lampp/apache2/conf``
  
  ``Alias /bitnami/ "/opt/lampp/apache2/htdocs/"``
  ``Alias /bitnami "/opt/lampp/apache2/htdocs"``
   ``Include etc/extra/httpd-vhosts.conf ``