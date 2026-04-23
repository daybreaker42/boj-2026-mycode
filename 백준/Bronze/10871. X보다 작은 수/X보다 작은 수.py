n, x = input().split()
n, x = int(n), int(x)
line = list(input().split())
for i in range(n):
    if int(line[i]) < x:
        print(int(line[i]), end = ' ')