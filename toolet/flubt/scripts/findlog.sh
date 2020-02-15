#!/bin/bash
shellpath=$(dirname $0)

if [[ ( $# -ne 2 ) ]]; then
    echo usage: $0 path pattern;
else
    if [[ $1 == "" || $2 == "" ]]; then
        echo "path and pattern cannot be empty, quit.";
        exit -1;
    elif [[ $1 == "-" || $2 == "-" ]]; then
	patterns=""
	while read line; do
		$patterns=$pattern $line		
	done < $shellpath/keys.in
	echo $patterns > $shellpath/find.out
	#locate spatterns > $shellpath/find.out
    else
	echo path=$1, pattern=$2
        find "$1" -iname "$2" > $shellpath/find.out
    fi
fi

