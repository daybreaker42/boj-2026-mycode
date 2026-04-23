t = int(input())
for i in range(t):
    n = int(input())
    lst = [1, 1, 1, 2, 2]
    if n < 5:
        print(lst[n-1])
    else:
        for i in range(5, n):
            lst.append(lst[i-1] + lst[i-5])
        print(lst[n-1])