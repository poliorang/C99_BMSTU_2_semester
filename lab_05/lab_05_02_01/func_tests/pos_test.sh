#!/bin/bash

ok=0
error_cmp=2
error_rc=3

file=$1
file_args=pos_${file:4:2}_args.txt

../app.exe $(cat "$file_args") <"$file" >out.txt
rc=$?

if [ ${rc} -ne 0 ]
then 
  echo -en "(rc == ${rc})"
  exit ${error_rc}
fi

file_one=pos_${file:4:2}_out.txt
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