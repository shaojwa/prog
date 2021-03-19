#!/bin/bash

cc=0
rc=0
wc=0

declare -a words

while read -r line
do
    let rc+=1
    for word in $line;
    do
       words[wc]=$word
       let wc+=1 
    done
done <file.txt

let -i cc=wc/rc

for ((i=0; i<cc; i++))
do
    line=''
    for((j=0; j<rc; j++))
    do
        if ((j!=0)); then line+=' ';fi
        line+=${words[j*cc+i]};
    done
    echo $line
done
