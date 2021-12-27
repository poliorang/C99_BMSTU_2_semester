#!/bin/shell
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -g -pg main.c -o app.exe
python gen.py 100000 > data.txt
./app.exe < data.txt
gprof app.exe > report.txt