#!/bin/bash

cd func_tests || exit

sh all_test.sh
cd ..

echo
echo -e "\e[33mCoverage\e[0m"
gcov main.c -r