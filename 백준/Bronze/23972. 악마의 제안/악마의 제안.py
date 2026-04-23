import sys, math
from decimal import *
k, n = map(Decimal, sys.stdin.readline().split())
if n == 1:
    print(-1)
else:
    print(math.ceil((k * n) / (n - 1)))