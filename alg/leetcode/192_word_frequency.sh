#!/bin/bash
declare -A map
while read -r line
do
    for word in $line; do
        flag=0
        for key in ${!map[*]}; do
            if [[ $key == $word ]]; then
                let -i map[$word]++; flag=1; break
            fi
        done

        if (( flag == 0 )); then
            map[$word]=1;
        fi
    done
done <words.txt

for key in ${!map[*]}; do echo $key ${map[$key]}; done | sort -nr -k 2
