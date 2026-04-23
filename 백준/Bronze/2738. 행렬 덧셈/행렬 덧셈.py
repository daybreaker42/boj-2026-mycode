import sys
n, m = map(int, sys.stdin.readline().split())

mat1 = []
mat2 = []
res = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    mat1.append(list(map(int, sys.stdin.readline().split())))
for i in range(n):
    mat2.append(list(map(int, sys.stdin.readline().split())))


for i in range(n):
    for j in range(m):
        res[i][j] = mat1[i][j] + mat2[i][j]

for i in range(n):
    for j in range(m):
        print(res[i][j], end=' ')
    print()