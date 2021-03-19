#!/bin/bash
p='^((\([0-9]{3}\)\ )|([0-9]{3}-))([0-9]{3}-[0-9]{4})$'
while read -r line
do
    if [[ $line =~ $p ]];
    then
        echo $line;
    fi
done <file.txt
