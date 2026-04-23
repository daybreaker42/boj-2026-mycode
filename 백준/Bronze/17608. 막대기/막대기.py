from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea: 내림차순 정렬
시간복잡도:
'''
n = int(input())
stick_lst = deque()
for i in range(n):
  val = int(input())
  while stick_lst and stick_lst[-1] <= val:
    stick_lst.pop()
  stick_lst.append(val)

print(len(stick_lst))
