import sys
n, m = map(int, input().split())
hear = set()
see = set()
for i in range(n):
    hear.add(sys.stdin.readline().strip('\n'))
for i in range(m):
    see.add(sys.stdin.readline().strip('\n'))
hear_see = sorted(list(hear & see))
print(len(hear_see))
for j in hear_see:
    print(j)