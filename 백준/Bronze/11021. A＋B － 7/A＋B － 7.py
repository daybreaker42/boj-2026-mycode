n = int(input())
for i in range(1, n+1):
    a, b = input().split()
    a, b = int(a), int(b)
    print('Case #', end = '')
    print(i, end = '')
    print(':', a+b)
