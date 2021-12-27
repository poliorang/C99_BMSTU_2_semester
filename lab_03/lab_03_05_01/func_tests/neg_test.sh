#!/bin/bash

error_rc=3

file=$1

../app.exe <"$file" >out.txt
rc=$?

if [ ${rc} -ne 0 ]
then 
  echo -e "${file} \e[32mPASSED\e[0m"
  exit ${error_rc}
fi