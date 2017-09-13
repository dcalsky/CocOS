sudo /sbin/losetup /dev/loop0 CocOS.img
sudo bochs -f /home/etharasuis/Desktop/bochsrc
sudo /sbin/losetup -d /dev/loop0
