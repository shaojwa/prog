#!/bin/bash

#filename=${1%.*}
filename=out

#pay attention to the space between : and -2
if [ "${1: -2}" == ".c" ];  then
#  echo "compile with gcc"
  gcc -Wall -g -o $filename $1 -lpthread
else
#  echo "compile with g++"
  g++ -std=c++11 -g -o $filename $1 -lpthread
fi
