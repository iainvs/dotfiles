#!/bin/bash
# env
export QT_QPA_PLATFORMTHEME=qt5ct # qt5ct usage
export DISPLAY=:0 # for xclip

# processes
feh --bg-fill ~/dotfiles/dwm/dwm/wallpaper/output.png & # wallpaper
/usr/lib/kdeconnectd & # starts kdeconnect

# dwm
# keeps dwm alive + logs errors
while true; do
    dwm >/tmp/dwm.log 2>&1
done

