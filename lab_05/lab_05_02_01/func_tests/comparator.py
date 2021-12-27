import sys

nums = '1234567890.- '
if len(sys.argv) > 1:
    f_ref = sys.argv[1]
    f_my = sys.argv[2]
    with open(f'{f_ref}') as f1:
        line = f1.readline().split()
        if 'Result:' in line:
            line = line[line.index('Result:'):]
            ans1 = ' '.join(line)
        else:
            ans1 = ' '.join(line)

    with open(f'{f_my}') as f2:
        line = f2.readline().split()
        if 'Result:' in line:
            line = line[line.index('Result:'):]
            ans2 = ' '.join(line)
        else:
            ans2 = ' '.join(line)
    if ans1.strip('\n').strip(' ') == ans2.strip('\n').strip(' '):
        print(0)
    else:
        print(1)