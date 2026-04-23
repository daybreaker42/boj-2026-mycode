import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''

n = int(input())
ans = 1
for i in range(1, n + 1):
  ans *= i

print(ans)