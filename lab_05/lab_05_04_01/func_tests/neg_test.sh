#!/bin/bash

ok=0
error_cmp=2

file=$1
num=${file:4:2}
file_args=neg_${num}_args.txt

../app.exe "$(cat "$file_args")" >shared/out.txt

file_one=shared/not_test_${num}.txt
file_two=shared/out.txt

diff "$file_one" "$file_two"
res=$?

if [ "$res" -eq 0 ]
then
  echo -e "${file_one} \e[32mPASSED\e[0m"
  rm shared/out.txt
  exit ${ok}
else
  echo -e "${file_one} \e[31mFAILED\e[0m"
  echo
  exit ${error_cmp}
fi