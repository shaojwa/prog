#!/bin/bash

msg="Nmap scan report for "
outfile=nmap.out
minrate=16
maxhostgroup=2
statefile=state.dat
logfile=state.log

# usage: scan iplist [-F]
function scan() {
    iplist=""
    port=""

    if [[ $1 == "" ]]; then
        echo "ERROR: no iplist"
        return 1
    fi
    iplist=$1
   
    if [[ ! -z $2  && $2 = "-F" ]]; then
             port="-F";
    fi

    argus=" -v $port --min-rate $minrate --max-hostgroup $maxhostgroup -iL $iplist -oN $outfile"
    echo $argus
    nmap $argus>/dev/null &
 }


g_ip=""
g_pid=""
#usage state get|set ip|pid
function state() {
    arguerr="arguemnts error"
    usage="get|set ip|pid"
 
    if [[ ( $# -ne 2 && $# -ne 3 ) || ( $1 != "get" && $1 != "set" ) ]]; then
        echo "EROR: $arguerr: $usage"
        return 1
    fi
    
    if [[ $2 != "pid" && $2 != "ip" ]]; then
        echo "EROR: $arguerr: $usage"
        return 1
    fi

    if [[ ! -e $statefile ]]; then 
        echo "ERROR: no file: $statefile"
        return 1
    else
        linenum=0
	while read -r pid ip; do
            ((linenum++))
            if [[ $linenum -eq 2 ]]; then break; fi
	done < $statefile
        #echo "linenum=$linenum $statefile"
        
        if [[ $linenum -ne 2 ]]; then
	   echo -e "\n\n" >$statefile
           return 1
        fi
        
        echo "INFO: read file: pid=$pid ip=$ip" >>$logfile

	if [[ $1 = "get" ]]; then
		if [[ $2 = "pid" ]]; then
	            g_pid=$pid
		elif [[ $2 = "ip" ]]; then
		    g_ip=$ip
		fi
	fi 

        if [[ $1 = "set" ]]; then 
	    if [[ $2 = "pid" ]]; then
	        echo set pid to $3 >>$logfile
                sed -i -u "2s/.*/$3 $ip/" $statefile
            elif [[ $2 = "ip" ]]; then
                echo set ip to $3 >>$logfile
                sed -i -u "2s/.*/$pid $3/" $statefile
            fi
        fi

        return 0
    fi 
}


#
# parse the log file
# usage: parse pid
#
function parse() {
    echo "do parsing $outfile ..." >>$logfile
    count=0
    lastip=""
    while [[ ! -e $outfile ]]; do 
        sleep 1
    done 
    
    echo "$outfile exists" >>$logfile
 
    firstline=""
    while [[ "$firstline" = "" ]]; do
       echo "ERROR: firstline empty" >>$logfile 
       firstline=$(head -1 $outfile)
       sleep 1
    done

    echo "$firstline" >>$logfile
    
    sed -i -u "1s/.*/$firstline/" $statefile

    nmap_exist=$(ps aux | grep $1 | grep nmap | wc -l)
    echo "INFO: nmap_exist=$nmap_exist" >>$logfile

    while [[ nmap_exist -ne 0 ]]; do

        ip=$(tail -20 $outfile | grep "Nmap scan report for" | tail -1 | grep -o [0-9\.]*)
        echo "INFO: get ip=$ip" >>$logfile
        if [[ "$ip" != "" && "$lastip" != "$ip" ]]; then
           lastip=$ip
           echo "INFO: lastip=$ip" >>$logfile
           state set ip $lastip
        fi 
        sleep 1
        nmap_exist=$(ps aux | grep $1 | grep nmap | wc -l)
        echo "INFO: nmap_exist=$nmap_exist" >>$logfile
        ((count++))
    done 

	ip=$(tail -20 $outfile | grep "Nmap scan report for" | tail -1 | grep -o [0-9\.]*)
	echo "INFO: get ip=$ip" >>$logfile
	if [[ "$ip" != "" ]]; then
		echo "INFO: lastip=$ip" >>$logfile
		state set ip $ip
        fi 
}


#
# syntax: scan.sh [ run | kill | resume ]"
#
if [[ $1 = "run" ]]; then
    echo "start scan at $(date +%H:%M:%S)"
    
    if [[ ! -e $statefile ]]; then
        touch $statefile
    fi

    nmap_exist=0
    state get pid
    retval=$?
    echo "get pid returns $retval"
    if [[ $retval -eq 0 ]]; then 
        nmap_exists=$(ps aux | grep $g_pid | grep nmap | wc -l)
    fi

    if [[ nmap_exists -eq 1 ]]; then
       echo "WARN: nmap is running (pid=$g_pid)"
    else
       scan list.txt "-F"
       nmap_pid=$!
       echo "run nmap instance (nmap_pid=$!)"
       state set pid $nmap_pid
       parse $nmap_pid >/dev/null &
    fi
elif [[ $1 = "kill" ]]; then
    state get pid
    echo "kill nmap (pid=$g_pid)"
    kill -9 $g_pid
elif [[ $1 = "resume" ]]; then
    nmap_exists=0
    state get pid
    retval=$?
    if [[ $retval -eq 0 ]]; then
        nmap_exists=$(ps aux | grep $g_pid | grep nmap | wc -l)
    fi

    if [[ nmap_exists -eq 1 ]]; then
       echo "ERROR: nmap is running (pid=$g_pid)"
       break
    fi

    state get ip
    if [[ $? -eq 0 ]]; then 
	echo g_ip=$g_ip
	echo "resume nmap..."
        record=$msg$g_ip
        head -1 $statefile >$outfile
        echo -e "$record\n" >>$outfile
        nmap --resume $outfile >/dev/null &
        nmap_pid=$!
        echo "resume nmap instance (nmap_pid=$!)"
        state set pid $nmap_pid
        parse $nmap_pid >/dev/null &
    else 
        echo "ERROR: resume failed"
    fi
else
    echo "usage: $0 [ run | kill | resume ]"
fi

