import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''

n = int(input())
cnt = 1

while n > 1:
  if n % 2 == 0:
    n //= 2
  else:
    n = n *3 + 1
  cnt += 1

print(cnt)