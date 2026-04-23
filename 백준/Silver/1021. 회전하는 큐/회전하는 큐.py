from collections import deque
import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''



n, m = map(int, input().split())
target_lst = list(map(int, input().split()))

lst_sorted = list(range(1, n + 1))
# lst_with_idx = [(i, idx) for idx, i in enumerate(lst_sorted)]
dq = deque(lst_sorted)
ans = 0

# dq에서 target 찾아서 index 반환
def find_idx(target):
  for idx, i in enumerate(dq):
    if i == target:
      return idx
  return -1


for curr_target in target_lst:
  target_idx = find_idx(curr_target)
  if target_idx < 0:
    # 해당 수가 lst에 존재하지 않는 경우
    pass

  if target_idx <= len(dq) // 2:
    # 왼쪽으로 이동시키는 경우 - 절반 이하면 성공
    dq.rotate(-(target_idx))
    ans += target_idx
  else:
    dq.rotate(len(dq) - (target_idx))
    ans += len(dq) - (target_idx)

  ele = dq.popleft()
  m -= 1
  if m == 0:
    print(ans)
    break
