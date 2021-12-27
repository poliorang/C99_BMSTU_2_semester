#!/bin/shell
gcc -std=c99 -Werror -Wpedantic -Wextra -Wall -Wvla -Wfloat-equal -Wfloat-conversion main_0.c -o app_0.exe
for (( i = 1; i <= 1000; i++))
do
	python gen.py 10 >gen_10_0.txt
	python gen.py 100 >gen_100_0.txt
	python gen.py 1000 >gen_1000_0.txt
	python gen.py 10000 >gen_10000_0.txt
	./app_0.exe <gen_10_0.txt >>time_10_0.txt
	./app_0.exe <gen_100_0.txt >>time_100_0.txt
	./app_0.exe <gen_1000_0.txt >>time_1000_0.txt
	./app_0.exe <gen_10000_0.txt >>time_10000_0.txt
done

gcc -std=c99 -Werror -Wpedantic -Wextra -Wall -Wvla -Wfloat-equal -Wfloat-conversion main_1.c -o app_1.exe
for (( i=1; i <= 1000; i++))
do
	python gen.py 10 >gen_10_1.txt
	python gen.py 100 >gen_100_1.txt
	python gen.py 1000 >gen_1000_1.txt
	python gen.py 10000 >gen_10000_1.txt
	./app_1.exe <gen_10_1.txt >>time_10_1.txt
	./app_1.exe <gen_100_1.txt >>time_100_1.txt
	./app_1.exe <gen_1000_1.txt >>time_1000_1.txt
	./app_1.exe <gen_10000_1.txt >>time_10000_1.txt
done

gcc -std=c99 -Werror -Wpedantic -Wextra -Wall -Wvla -Wfloat-equal -Wfloat-conversion main_2.c -o app_2.exe
for (( i=1; i <= 1000; i++))
do
	python gen.py 10 >gen_10_2.txt
	python gen.py 100 >gen_100_2.txt
	python gen.py 1000 >gen_1000_2.txt
	python gen.py 10000 >gen_10000_2.txt
	./app_2.exe <gen_10_2.txt >>time_10_2.txt
	./app_2.exe <gen_100_2.txt >>time_100_2.txt
	./app_2.exe <gen_1000_2.txt >>time_1000_2.txt
	./app_2.exe <gen_10000_2.txt >>time_10000_2.txt
done
python time_avg.py
python data.py >data.txt
