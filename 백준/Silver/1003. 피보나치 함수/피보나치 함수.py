t = int(input())
for i in range(t):
    n = int(input())
    lst = [0] * (n+2)
    lst[n] = 1
    if n > 1:
        for j in range(n, 1, -1):
            lst[j-1] += lst[j]
            lst[j-2] += lst[j]
        lst[0] = lst[2]
    print(lst[0], lst[1])