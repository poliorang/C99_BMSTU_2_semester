for i in range(3):
    n = 10
    for j in range(4):
        f = open(f'time_{n}_avg_{i}.txt')
        for line in f:
            print(n, line)
        n *= 10
    f.close()
