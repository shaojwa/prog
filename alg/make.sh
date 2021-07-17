#!/bin/bash

#pay attention to the space between : and -2
if [ "${1: -2}" == ".c" ];  then
  # echo "compile with gcc"
  compile='gcc -g'
else
  # echo "compile with g++"
  compile='g++ -g -std=c++11 -fno-default-inline'
fi

if [ "${2}" == "-c" ];  then
  $compile -c $1 -ldl -lpthread
elif [ "${2}" == "-s" ];  then
  $compile -S $1 -ldl -lpthread
elif [ "${2}" == "-e" ];  then
  $compile -E $1 -ldl -lpthread
else
  $compile -o out $1 -ldl -lpthread
fi
