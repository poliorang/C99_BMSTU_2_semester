#!/bin/shell
gcc -std=c99 -Werror -Wpedantic -Wextra -Wall -Wvla -Wfloat-equal -Wfloat-conversion -g3 main.c -o app.exe --coverage