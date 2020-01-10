#!/bin/bash

#pay attention to the space between : and -2
if [ "${1: -2}" == ".c" ];  then
  echo "compile with gcc"
  gcc -g -o out $1 -ldl -lpthread
else
  echo "compile with g++"
  g++ -std=c++0x -g -o out $1 -ldl -lpthread
fi
