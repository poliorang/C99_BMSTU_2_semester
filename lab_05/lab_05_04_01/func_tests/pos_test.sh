#!/bin/bash

ok=0
error_cmp=2
error_rc=3

file=$1
num=${file:4:2}
file_args=pos_${num}_args.txt

arg=$(cat "$file_args")

if [ "${arg:0:2}" == "fb" ]
then 
  ../app.exe $(cat "$file_args")
  rc=$?
  
  if [ ${rc} -ne 0 ]
  then 
    echo -e "\e[31mFAILED\e[0m"
    echo -en "(rc == ${rc})"
    exit ${error_rc}
	echo
  fi
  
  ../app.exe re "${arg:22:22}" >shared/out.txt
  
  file_one=shared/test_${num}.txt
  file_two=shared/out.txt

  diff "$file_one" "$file_two"
  res=$?
  if [ "$res" -eq 0 ]
  then
    echo -e "${file_one} \e[32mPASSED\e[0m"
	rm shared/out.txt
    exit ${ok}
	echo
  else
    echo -e "${file_one} \e[31mFAILED\e[0m"
	rm shared/out.txt
    exit ${error_cmp}
	echo
  fi
fi

if [[ ${arg:0:2} == "sb" ]] 
then
  ../app.exe $(cat "$file_args") >shared/out.txt
  rc=$?

  if [ ${rc} -ne 0 ]
  then 
    echo -e "\e[31mFAILED\e[0m"
    echo -en "(rc == ${rc})"
    exit ${error_rc}
	echo
  fi
  
  file_one=shared/test_${num}.txt
  file_two=shared/out.txt

  diff "$file_one" "$file_two"
  res=$?
  
  if [ "$res" -eq 0 ]
  then
    echo -e "${file_one} \e[32mPASSED\e[0m"
    rm shared/out.txt
    exit ${ok}
	echo
  else
    echo -e "${file_one} \e[31mFAILED\e[0m"
	rm shared/out.txt
    exit ${error_cmp}
	echo
  fi

fi

if [[ ${arg:0:2} == "db" ]] 
then
  ../app.exe $(cat "$file_args")
  rc=$?

  if [ ${rc} -ne 0 ]
  then 
    echo -e "\e[31mFAILED\e[0m"
    echo -en "(rc == ${rc})"
    exit ${error_rc}
	echo
  fi
  
  ../app.exe re "${arg:3:25}" >shared/out.txt
  
  file_one=shared/test_${num}.txt
  file_two=shared/out.txt

  diff "$file_one" "$file_two"
  res=$?
  if [ "$res" -eq 0 ]
  then
    echo -e "${file_one} \e[32mPASSED\e[0m"
    rm shared/out.txt
    exit ${ok}
	echo
  else
    echo -e "${file_one} \e[31mFAILED\e[0m"
	rm shared/out.txt
    exit ${error_cmp}
	echo
  fi
fi
