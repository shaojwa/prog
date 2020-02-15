#!/bin/bash

backup=""
findout="find.out"
line=""
count=0
foldername=""
logfile="run.log"
error=0

echo ----begin---- >> $logfile
echo $(date) >> $logfile

if [[ ( $# -ne 1 ) ]]; then
    echo usage: $0 path;
else
    if [[ $1 == "" ]]; then
        echo "path and pattern cannot be empty, quit.";
        exit 1;
    fi
    backup=$1
    foldername=$(date +%Y%m%d-%H%M%S);
    mkdir $backup/$foldername;
    if [[ ( $? -ne 0) ]]; then exit 1; fi
    echo $backup/$foldername >> $logfile;
    while read -r line; do
        ((count++));
	subdir=$backup/$foldername/$count;	
	mkdir $subdir;
	cp -r $line $subdir;
    done < $findout
fi
echo ----end---- >> $logfile

