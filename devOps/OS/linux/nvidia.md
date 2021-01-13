```

sudo dpkg-reconfigure gdm

sudo apt-get purge 'nvidia*'

sudo add-apt-repository ppa:graphics-drivers

sudo apt-get update

suso apt-get install nvidia-387

reboot

sudo nano /etc/default/grub # nomodeset

sudo update-grub

reboot

```
Mình cũng gặp lỗi tương tự thế này (lúc thì không login được, lúc thì sau khi login chỉ hiện màn hình đen, có khi login xong thì đơ đơ, không thao tác được gì …), google mãi, bác thì bảo do MRB, GPT, bác thì bảo do gdm3, lightDM, bác thì bảo do driver …

Sau một thời gian tìm được cách fix được thì sướng như lên tiên ấy, mà cách fix cũng đơn giản chứ không phức tạp, nên mình share lại tất cả các trang mình đã search, hi vọng có thể hữu ích cho ai đó, đỡ tốn thời gian như mình vừa rồi. Chứ còn thực sự hiểu bản chất thì xin phép, mình chưa phải cao thủ.

Về cơ bản thì lý do là khi khởi động grub, Ubuntu được config mặc định sẽ khởi động một số thứ có dính lứu tới card rời Nvidia và vấn đề nằm ở driver Nvidia.

Ngày xửa ngày xưa, Nvidia có cung cấp các thông số để cộng đồng mã nguồn mở viết driver Nvidia cho Linux nên các dòng máy có dùng card Nvidia đời cũ sẽ không gặp lỗi này.
Ví dụ như máy Lenove B450 ngày trước mình dùng thì cài song song Ubuntu và Windows ngon lành.
Vừa rồi mua mới con Acer Nitro 5, trang bị Nvidia đời mới hơn thì gặp lỗi trên.

Mới đây, Nvidia đã ngừng công bố các thông số cần thiết để cộng đồng mã nguồn mở viết driver Nvidia cho họ Linux (mặc dù có cuba với linux bumblebee nhưng mình cài thử vẫn chưa fix được), thế nên những dòng máy có card rời Nvidia đời mới rất dễ gặp lỗi trên, ngoài ra còn nhiều vấn đề nữa. Còn card rời AMD thì khác, thấy bảo họ cung cấp đầy đủ thông số rồi và có driver ngon nghẻ.

Cách fix như sau:

Khi đang vào Ubuntu thì nhấn Ctrl + Alt + F1 -> F6 (Bạn chọn từ F1 tới F6 nhé, miễn sao vào được Vitural Terminal, còn muốn quay trở lại GUI thì ấn Alt + Ctrl + F7),

Gõ

 sudo nano /etc/default/grub
Nhìn thấy dòng:

GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
Sửa thành:

GRUB_CMDLINE_LINUX_DEFAULT="quiet splash nomodeset"
Cập nhật lại grub rồi khởi động lại máy
sudo update-grub
sudo reboot
Okie, lúc này bạn đã có thể làm việc với Ubuntu bình thường rồi.

Một thời gian sau, mình sử dụng cổng HDMI để làm việc trên màn hình lớn thì thi thoảng lại không xuất ra được.
Cách fix: Bây giờ thì bắt buộc phải cài driver cho Nvidia rồi.
Cách 1:

sudo dpkg-reconfigure gdm

sudo apt-get purge 'nvidia*'

sudo add-apt-repository ppa:graphics-drivers

sudo apt-get update

suso apt-get install nvidia-387

reboot
Cách 2:
Có thể thử công cụ Additional Driver

image.png
1041×476 94.6 KB
Sau đó, khi khởi động lại máy, nếu gặp hiện tượng login xoay vòng thì vào Visual Terminal cập nhật lại grub:
sudo update-grub

Nguồn:

https://askubuntu.com/a/150626 81
https://forums.linuxmint.com/viewtopic.php?t=168108 40
https://askubuntu.com/questions/851432/how-do-i-edit-ubuntu-16-10-grub-menu-to-remove-gfxmode/852142#852142 28
Đọc để hiểu thêm tại:

https://askubuntu.com/questions/716957/what-do-the-nomodeset-quiet-and-splash-kernel-parameters-mean/716966 35
