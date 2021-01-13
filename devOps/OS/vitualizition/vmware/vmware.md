Forward port to VMware machine using iptables
================================================

Operating system: Centos 6.6

Enable ipv4 forward
--------------------------------------------------
 
 `vi /etc/sysctl.conf`
 
 Change value `net.ipv4.ip_forward` to 1
 
 `net.ipv4.ip_forward = 1`
 
Change iptables service
---------------------------------------------------
 
 `vi /etc/sysconfig/iptables`
 
 Forward port 8080 to port 80 in 172.16.81.100
 
 `-A PREROUTING -p tcp -m tcp --dport 8080 -j DNAT --to-destination 172.16.81.100:80`
 
 Enable POSTROUTING for network card
 
  `-A POSTROUTING -o vmnet8 -j MASQUERADE`
  
 Set up response to real machine (IP: xxx.xxx.xxx.xxx)
 
 `-A POSTROUTING -s 172.16.81.100/32 -j SNAT --to-source xxx.xxx.xxx.xxx`
 
 Firewall port 8080
 
 `-A INPUT -p tcp -m state --state NEW -m tcp --dport 8080 -j ACCEPT`
 
 Restart iptables services
 
  `service iptables restart`
 
### Firewall port 80 in virtual machine if needed

### Can't use this setting for PostgreSQL, if you want to forward port for PostgreSQL, you should use vmware nat config


Forward port to VMware machine using vmware nat config
================================================

Step 1: Turn off or suspend all the virtual machine

Step 2: Edit nat network config

`vi /etc/vmware/vmnet8/nat/nat.conf`

Add this information to `[tcp]` and `[udp]`: forward port 5432 to port 5432 on 172.16.81.100

`5432 = 172.16.81.100:5432`

Step 3: Restart vmware service (require turn off all the virtual machine)

`service vmware restart`


Change setting for folder shared VM
===================================================

Change port ssl vmware workstation server: 

`vi /etc/vmware/hostd/proxy.xml`

Change folder default `standard`

`vi /etc/vmware/hostd/datastores.xml`
