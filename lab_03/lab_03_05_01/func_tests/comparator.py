import sys

numbers = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '-']
if len(sys.argv) > 1:
    buf = ''
    ans_one = ''
    ans_two = ''
    f_one = f'{sys.argv[1]}'
    f_two = f'{sys.argv[2]}'
    for line in f_one:
        for el in line:
            if el in numbers:
                buf += el
        ans_one += f'{buf.strip(" ")}'
        buf = ''
    for line in f_two:
        for el in line:
            if el in numbers:
                buf += el
        ans_two += f'{buf.strip(" ")}'
        buf = ''
    if ans_one == ans_two:
        print(1)
    else:
        print(0)