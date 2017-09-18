sudo /sbin/losetup /dev/loop0 CocOS.img
sudo bochs -f /home/etharasuis/Desktop/test/CocOS-feat-kernal-vfs/bochsrc
sudo /sbin/losetup -d /dev/loop0
