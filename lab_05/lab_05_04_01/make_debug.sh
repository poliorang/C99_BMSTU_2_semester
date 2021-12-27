#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -g3 -c --coverage main.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -g3 -c --coverage students.c
gcc -o app.exe --coverage main.o students.o