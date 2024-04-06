
n = int(input())

for i in range(1, 1+ n):
    if (i % 3) == 0:
        print('x', end='')
    else:
        print('o', end='')
