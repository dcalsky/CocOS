sudo /sbin/losetup /dev/loop0 CocOS.img
sudo bochs -f $(pwd)/bochsrc
sudo /sbin/losetup -d /dev/loop0
