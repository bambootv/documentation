1. xdotool

```bash
sudo apt-get install xdotool
xdotool key ctrl+shift+t
WID=$(xprop -root | grep "_NET_ACTIVE_WINDOW(WINDOW)"| awk '{print $5}')
xdotool windowfocus $WID
wmctrl -i -a $WID
xdotool key c d space slash m e d i a slash t r e v n slash D A T A 1 slash s m i t s minus a d s slash a p i minus g a t e w a y KP_Enter
xdotool key g i t space p u l l space o r i g i n space d e v KP_Enter
xdotool key n p m space r u n space u p KP_Enter
xdotool key n p m space r u n space d e v KP_Enter
```
