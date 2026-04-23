import sys
s = sys.stdin.readline().strip('\n')
p = sys.stdin.readline().strip('\n')
if p in s:
    print(1)
else:
    print(0)