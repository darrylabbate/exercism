#!/bin/sh

year=$1

if [ $((year % 400)) -eq 0 ]; then
  echo "True"
elif [ $((year % 100)) -eq 0 ]; then
  echo "False"
elif [ $((year % 4)) -eq 0 ]; then
  echo "True"
else
  echo "False"
fi
