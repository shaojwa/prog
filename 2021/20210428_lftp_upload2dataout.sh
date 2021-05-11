#!/bin/bash

# personal configs
local_file=./COMPILE/product.gz
personal_dir=_wsh

# ftp configs
ftp_ip=10.132.193.116
ftp_dir=data-out
ftp_user=vm-itproduct
ftp_passwd=pwd-vm-itproduct
sub_dir=$(date +%Y%m%d_%H%M%S)

# upload
md5sum $local_file
lftp -u $ftp_user,$ftp_passwd $ftp_ip << END
cd $ftp_dir/$personal_dir
mkdir -p $sub_dir
cd $sub_dir
put $local_file
exit
END
