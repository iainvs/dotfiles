1. Flash Arch ISO to a USB drive using Rufus. Keep all default settings.
2. Open BIOS/UEFI, disable secure boot, clear any keys/certificates after disabling secure boot, set USB as the primary boot device, save, and reboot. 
3. iwctl, device list, station wlan0 get-networks, station wlan0 connect [SSID], iwctl, ping google.com
5. lsblk, gdisk [DRIVE], x, z, y, y, lsblk
6. pacman -Syy, pacman -S archlinux-keyring, y, pacman -Sy archinstall, y, archinstall
7. Disk configuration > Use a best-effort default partition layout > [DRIVE] > btrfs > yes (default)
8. Add disk encryption password.
9. Bootloader > Grub > 
10. Set root password.
11. User account > Add a user > Add username > Add password for user > Confirm password > yes (default) > Confirm and exit
12. Profile > Type > Minimal > Back
13. Audio > Pipewire
14. Additional software > vim git wget curl neofetch wine firefox
15. Network configuration > Use NetworkManager
16. Timezone > Asia/Shanghai
17. Install
18. no
19. shutdown now
20. Once powered off, remove the USB and the system will boot into the Arch CLI.
21. sudo nmcli dev wifi connect [SSID] password ["PASSWORD"], ping google.com
22. git clone https://github.com/prasanthragan/hyprdots, cd hyprdots/Scripts, chmod +x ./install.sh, ./install.sh, 2, y, 1, 1, y, 1, 1, y, y, y, [PASSWORD], y, [PASSWORD]
23. Reboot and login. 

### Programs
1. Geany
2. Calculate
3. 