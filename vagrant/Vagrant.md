Vagrant file:

```
Vagrant.configure(2) do |config|
  config.vm.box = "centos/7"
  #config.vm.synced_folder "./", "/build/"
  config.vm.hostname = "dev-server"
  config.vm.network "private_network", ip: "172.20.20.20"

  config.vm.provider "virtualbox" do |vb|
    vb.gui = false
    vb.memory = 2048
    vb.cpus = 1
  end
  config.vm.provision "shell", inline: <<-SHELL
    yum update
    yum install -y whois git
    useradd -m -p `mkpasswd password` -s /bin/bash dev
    usermod -a -G sudo dev
  SHELL
end
```

If you see this error: `There was an error when attempting to rsync a synced folder.`, you should install vb-guest plugin via:

`vagrant plugin install vagrant-vbguest`
