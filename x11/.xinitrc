#!/bin/bash 
export QT_QPA_PLATFORMTHEME=qt5ct
feh --bg-fill ~/dotfiles/dwm/dwm/wallpaper/output.png & 
exec dwm

xsetroot -name ""

/usr/lib/kdeconnectd &

while true; do
  dwm >/tmp/dwm.log 2>&1
done
