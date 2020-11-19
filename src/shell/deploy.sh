#!/bin/bash

#set -x
set -u
set -e

cifs() {
  if [ $# -ne 3 ]; then echo "usage: cifs <username> <password> <ip>"; exit 1; fi
  username=$1
  password=$2
  ip=$3
  sudo mount -t cifs -o username=$username,password=$password //$ip/cifs /mnt/cifs
}

nfs() {
  if [ $# -ne 2 ]; then echo "usage: nfs <ip> <path>"; exit 1; fi
  ip=$1
  path=$2
  sudo mount -t nfs $ip:$path/nfs /mnt/nfs
}

hstnm() {
  if [ $# -ne 2 ]; then echo "usage: hostname <ip> <hostname>"; exit 1; fi
  ip=$1
  name=$2
  ssh -n root@$ip "echo $name > /etc/hostname"
}

interface() {
  if [ $# -ne 3 ]; then echo "usage: interface <ip> <ifname> <ifip>"; exit 1; fi
  ip=$1
  ifname=$2
  ifip=$3
  ssh -n root@$ip "echo -e '\nauto $ifname\niface $ifname inet static\naddress $ifip \nnetmask 255.255.255.0\n' >> /etc/network/interfaces"
}


ifreload() {
  if [ $# -ne 2 ]; then echo "usage: ifreload <ip> <ifname>"; exit 1; fi
  ip=$1
  ifname=$2
  ssh -n root@$ip "ifdown $ifname; ifup $ifname"
}


hosts() {
  if [ $# -ne 2 ]; then echo "usage: hosts <ip> <hostname>"; exit 1; fi
  ip=$1
  hostname=$2
  ssh -n root@$ip "sed -i 's/\<\(node\|client\)\w*/$hostname/g' /etc/hosts"
}

rbt() {
  if [ $# -ne 1 ]; then echo "usage: reboot <ip>"; exit 1; fi
  ip=$1
  ssh -n root@$ip reboot
}

set_ssh() {
  if [ $# -ne 1 ]; then echo "usage: ssh <ip>"; exit 1; fi
  cd ~
  ip=$1
  ssh-keygen -f ~/.ssh/known_hosts -R $ip
  ssh-copy-id root@$ip
}

apt() {
  if [ $# -ne 1 ]; then echo "usage: apt <ip>"; exit 1; fi
  cd ~
  ip=$1
  ssh -n root@$ip "cp /etc/apt/sources.list  /etc/apt/sources.list.bak"
  scp sources.list root@$ip:/etc/apt/sources.list
  ssh -n root@$ip "apt update"
}

kernel() {
  if [ $# -ne 2 ]; then echo "usage: kernel <path> <ip>"; exit 1; fi
  deb_path=$1
  ip=$2
  ssh -n root@$ip "rm ~/*.deb"
  scp $deb_path/linux-image*  $deb_path/linux-header* root@$ip:~
}

bashrc() {
  if [ $# -ne 1 ]; then echo "usage: bashrc <ip>"; exit 1; fi  
  ip=$1
  ssh -n root@$ip "echo -e '\nbind \"\C-d\":kill-word\nbind \"\C-b\":backward-word\nbind \"\C-f\":forward-word\n' >> ~/.bashrc"
}

tch() {
  if [ $# -ne 2 ]; then echo "usage: $0 <dir> <count>"; exit 1; fi                                                                                                                     
  dir=$1                                                                                                                                                                                
  max=$2                                                                                                                                                                                
  id=0                                                                                                                                                                                  
  if [ ! -e $dir ]; then echo "error: dir not exist"; exit 1; fi                                                                                                                          
   while [ $id -lt $max ]; do                                                                                                                                                            
     touch $dir/filex$id                                                                                                                                                                 
     ((++id))
   done 
}

gen_ltags() {
  if [ $# -ne 1 ]; then echo "usage: ltags <path>"; exit ;fi
  cd $1
  echo -e "!_TAG_FILE_SORTED\t2\t" > ltags
  find . \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -type f -printf "%f\t%p\t1\n" | sort -f >> ltags
  #find . -regex '.*\.\(h\|c\|cc\)' -type f -printf "%f\t%p\t1\n" | sort -f >> ltags
  sed -i 's/^[_0-9a-zA-Z]\+/\L&/' ltags
}


gen_ctags() {
  if [ $# -ne 1 ]; then echo "usage: ctags <path>"; exit 1; fi
  cd $1
  find . \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -type f > project.files
  ctags -L project.files --c++-kinds=+p --fields=+iaS --extra=+q --language-force=c++
}

gen_cscope() {
  if [ $# -ne 1 ]; then echo "usage: cscope <path>"; exit 1 ; fi
  cd $1
  find . \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -type f > cscope.files
  cscope -bq
}


help() {
  echo "usage: $0 {ssh|bashrc|interface|reboot|nfs|cifs|ifreload|help}"
  exit 1
}

main () {
  if [ $# -eq 0 ]; then help; exit -1; fi
  case $1 in 
    (apt)
      func=apt
      ;;
    (cifs)
      func=cifs
      ;;
    (help)
      func=help
      ;;
    (ifreload)
      func=ifreload
      ;;
    (interface)
      func=interface
      ;;
    (kernel)
      func=kernel
      ;;
    (nfs)
      func=nfs
      ;;
    (reboot)
      func=rbt
      ;;  
    (ssh)
      func=set_ssh
      ;;
    (bashrc)
      func=bashrc
      ;;
    (touch)
      func=tch
      ;;
    (ltags)
      func=gen_ltags
      ;;
    (ctags)
      func=gen_ctags
      ;;
    (cscope)
      func=gen_cscope
      ;;
    (su)
      do_su
      ;;
    (*)
      help
      ;;
    esac

    while read -r line; do
      $func $line
    done
}

main $@
