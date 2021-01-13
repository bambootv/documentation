```
# https://askubuntu.com/questions/851432/how-do-i-edit-ubuntu-16-10-grub-menu-to-remove-gfxmode/852142#852142
GRUB_CMDLINE_LINUX_DEFAULT="agp=off quiet splash nox2apic nomodeset"
sudo update-grub
```

```
sudo add-apt-repository ppa:yannubuntu/boot-repair
sudo apt-get update
sudo apt-get install -y boot-repair && boot-repair
```
