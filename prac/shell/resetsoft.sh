#!/bin/bash -u

# find the quotas and reset the soft threshold to 0

mds_ip=$(ceph mds dump 2>&1 | grep up | grep active | egrep -o '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}')
if test x$mds_ip = x; then echo "error: cannot get active mds ip"; exit 1; fi

ssh root@$mds_ip &> /var/log/reset_soft.log  <<'EOF'
  mds=$(ceph -s | grep 'up:active' | grep -o 'mds[0-9]')
  if test x$mds = x; then echo "error: cannot find active mds"; exit 1; fi

  if ! ps aux | grep ceph-mds | grep $mds &> /dev/null; then
    echo "error: not the active mds node"; exit 1
  fi
  # quuery quotas
  result=$(ceph daemon mds.$mds quota query -1)
  if test x$result = x; then echo "error: quota query fail"; exit 1; fi

  # get quotas content
  OLD_IFS=$IFS;
  IFS=":"
  arr=($result)
  IFS=$OLD_IFS
  quotas=${arr[1]-""}
  if test x$quotas = x; then echo "no quotas"; exit 1; fi

  # split quotas
  OLD_IFS=$IFS
  IFS=";"
  arr=($quotas)
  for quota in ${arr[@]}; do
    IFS=","
    items=($quota)
    id=${items[0]}
    method=${items[6]}
    hard=${items[7]}
    soft=${items[8]}
    advice=${items[9]}
    extend=${items[10]}
    if test $soft -ne 0; then
      ceph daemon mds.$mds quota modify $id $method $hard 0 $advice 0 &> /dev/null
    fi
    IFS=";"
  done
  IFS=$OLD_IFS
  exit 0
EOF

exit 0
