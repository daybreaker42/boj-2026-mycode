from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''
k = int(input())
dq = deque()
for i in range(k):
  val = int(input())
  if val > 0:
    dq.append(val)
  else:
    dq.pop()

total = 0
for num in dq:
  total += num

print(total)