from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''
n = int(input())
for i in range(n):
  str_lst = input().rstrip().split()
  s = deque()
  for word in str_lst:
    s.append(word)
  print(f'Case #{i + 1}:', end=' ')
  while s:
    print(s.pop(), end=' ')
  print()