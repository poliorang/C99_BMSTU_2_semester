k = 10
for i in range(3):
    n = 10
    for j in range(4):
        f = open(f'time_{n}_{i}.txt')
        f_out = open(f'time_{n}_avg_{i}.txt', 'w')
        sum = 0
        for line in f:
            sum += float(line)
        f_out.write(str(sum / k))
        n *= 10
        f.close()
        f_out.close()