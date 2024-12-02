#!/bin/bash

for ((i=2; i<=$1; i++)) do  
  if (( $1 % i == 0)); then
    echo "Not Prime"
    exit 0
  fi
done 
