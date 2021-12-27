#!/bin/bash

ok=0
error_cmp=2
error_rc=3

file=$1

../app.exe <"$file" >out.txt

file_one=neg_${file:4:2}_out.txt
file_two=out.txt

res=$(python comparator.py "$file_one" "$file_two")

if [ "$res" -eq 0 ]
then
  echo -e "${file_one} \e[32mPASSED\e[0m"
  rm out.txt
  exit ${ok}
else
  echo -e "${file_one} \e[31mFAILED\e[0m"
  echo
  exit ${error_cmp}
fi