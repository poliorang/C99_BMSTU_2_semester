#!/bin/bash
rm -rf ./*.gcov ./*.gcda ./*.gcno
echo
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -c --coverage main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -c --coverage shortstrings.c 
gcc -o app.exe --coverage main.o shortstrings.o 

./app.exe

rc=$?
echo
echo
if [ ${rc} -eq 0 ]
then 
  echo -en "\e[32mPASSED\e[0m"
fi
echo 
echo
echo -e "\e[33mCoverage main.c\e[0m"
gcov main.c -r
echo -e "\e[33mCoverage shortstrings.c\e[0m"
gcov shortstrings.c -r