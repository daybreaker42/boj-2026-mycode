from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''

MAX = 10_000
is_not_prime = [False] * (MAX + 1)

i = 2
ans = -1
prime_tried = set()
while i * i <= MAX:
  if is_not_prime[i]:
    i += 1
    continue
  for j in range(i * 2, MAX + 1, i):
    is_not_prime[j] = True
  i += 1

def is_prime(n):
  return not is_not_prime[n]

# bfs
def get_min_num(start, end):
  global ans
  # prime_tried 기록
  prime_tried = set([start])

  # 큐 생성
  waiting_q = deque([(start, 0)])
  waiting_set = set([start])

  while waiting_q:
    front, curr_cnt = waiting_q.popleft()
    waiting_set.remove(front)
    prime_tried.add(front)

    # 된다면?
    if front == end:
      ans = curr_cnt
      break

    # 정수 리스트로 변환
    front_to_list = list(map(int, str(front)))
    # front_list_editted = front_to_list.copy()

    # 
    for digit_index in range(4):
      for new_digit in range(10):
        if digit_index == 0 and new_digit == 0:
          # 첫째자리 0은 안됨
          continue
        if new_digit == front_to_list[digit_index]:
          # 기존 숫자와 같음 방지
          continue
        front_list_editted = front_to_list.copy()
        front_list_editted[digit_index] = new_digit
        front_editted = int(''.join(map(str, front_list_editted)))

        if is_prime(front_editted) and front_editted not in prime_tried and front_editted not in waiting_set:
          # 조건만족시 넣음
          waiting_q.append((front_editted, curr_cnt + 1))
          waiting_set.add(front_editted)


t = int(input())
for _ in range(t):
  start, end = map(int, input().split())
  get_min_num(start, end)
  if ans >= 0:
    print(ans)
  else:
    print('Impossible')