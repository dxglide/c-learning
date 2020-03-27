#!/bin/bash
gcc -v

if [ $? != 0 ]; then
   echo "GCC os not installed !"
fi

ld -v
if [ $? != 0 ]; then
   echo "Binutils  is  not installed !"
fi





