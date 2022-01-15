mkdir -p /opt/swap/
cd /opt/swap/
sudo dd if=/dev/zero of=swapfile bs=1024 count=3145728
sync
du -sh swapfile 
sudo mkswap swapfile
sudo swapon swapfile #
# free -m
# free -h
# sudo swapon -s

# 删除
#swapoff     swapfile
#rm    swapfile 
