import sys

nums = '1234567890.- '
if len(sys.argv) > 1:
    f_res = sys.argv[1]
    f_my = sys.argv[2]
    with open(f'{f_res}') as f1:
        ans1 = f1.readline()

    with open(f'{f_my}') as f2:
        ans2 = f2.readline()

    if ans1.strip('\n').strip(' ') == ans2.strip('\n').strip(' '):
        print(0)
    else:
        print(1)