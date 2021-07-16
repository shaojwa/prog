#!/bin/bash

pool_id=6
nodes_num=3

## functions

usage() {
  echo "usage: $0 { rcache | dm }  { stat | clear | restat }"
}

rcache() {
  if [ $# -ne 1 ]; then
    usage;
    return;
  fi
  if [[ ! "$1" =~ ^(stat|clear|restat) ]]; then
    usage;
    return;
  fi
  engines=$(ceph engine ls | grep $pool_id.)
  total_eng_num=$(ceph engine ls | grep $pool_id. | wc -l)
  node_eng_num=$(( $total_eng_num / $nodes_num))
  index=0;
  for e in $engines; do
    if [[ $(($index / $node_eng_num)) == 0 ]]; then
      host=node73;
    elif [[ $(($index / $node_eng_num)) == 1 ]]; then
      host=node74;
    else
      host=node75;
    fi
    ((index++))
    echo engine.$e in $host
    ssh -o LogLevel=ERROR $host ceph daemon dse.${host} engine $e dcache rcache $1
  done
}

main() {
  if [ $# -eq 0 ]; then
    usage;
    exit -1;
  fi

  case $1 in
    (rcache)
    shift
    rcache $@
    ;;
  esac
}

main $@
