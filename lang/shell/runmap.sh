#!/bin/bash

scan() {

    if [[ $# != 5 ]]; then 
        echo 'usage: scan <list_num> "-F"|"" <min-rate> <iplist_path> <outpath>'
        return
    fi

    index=""
    if [[ $1 != 0 ]]; then index=$1; fi
    hosts="$4/list$1.txt"

    port=""

    if [[ ! -z $2  && $2 = "-F" ]]; then
             port="-F";
    fi

    logfile="out$1$port-$(date +%s).txt"

    argus=" $port --min-rate $3 -iL $hosts -oN $4/$logfile"
    echo $argus
    nmap $argus
 }


echo "---- start scan at $(date +%H:%M:%S) ----"
bound=1
for (( i = 0; i < bound; i++ )) ; do
  scan $i "-F" 1024 ".." ".."
  echo finish scan list "#$i" at $(date +%H:%M:%S)
done

echo "---- finish scan at $(date +%H:%M:%S) ----"

