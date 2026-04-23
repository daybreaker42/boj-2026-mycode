n = int(input())
for i in range(n):
    k = n
    for j in range(i):
        print(end = ' ')
    while (k - i) > 0:
        k -= 1
        print('*', end = '')
    print(sep = ' ')