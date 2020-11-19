#!/bin/bash

arr=("one" "two" "three")
echo "length of arr = ${#arr[*]}"

for i in "${arr[@]}"; do
    echo $i
done

echo ${arr[@]:2}

n=1
m=1
let count=0
echo "rs=$?"
let count=1
echo "rs=$?"


if (( n - m ));  then
    echo "return=$a"
else
    echo "statue=$?"
fi


if [[ -a bashtest.sh ]] ; then
    echo "file exist"
else 
   echo "file not exit"
fi

