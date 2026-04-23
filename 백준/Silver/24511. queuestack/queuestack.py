from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''
n = int(input())
is_stack_lst = list(map(int, input().split()))
init_value_lst = list(map(int, input().split()))
m = int(input())
input_lst = list(map(int, input().split()))

# 전체 queue
q1 = deque()
for i in range(n):
  if not is_stack_lst[n - i - 1]:
    q1.append(init_value_lst[n - i - 1])

# for i in range(m):
q1.extend(input_lst)


for i in range(m):
  print(q1.popleft(), end=' ')


# for i in range(m):
#   val = input_lst[i]
#   for j in range(n):
#     if not is_stack_lst[j]:
#       queuestack[j], val = val, queuestack[j]
#   print(val, end=' ')


# 23
# for i in range(m):
#   # 삽입을 m번 반복
#   push_val = input_lst[i]
#   popped_val = -1
#   queuestack_lst[0].append(push_val)
#   for j in range(n):
#     if is_stack_lst[j]:
#       popped_val = queuestack_lst[j].pop()
#     else:
#       popped_val = queuestack_lst[j].popleft()

#     if j < n - 1:
#       # j가 마지막이 아니라면 - 다음 번째 자료구조에 push
#       queuestack_lst[j + 1].append(popped_val)
#   print(popped_val, end=' ')

