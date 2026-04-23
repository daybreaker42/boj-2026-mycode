import sys
input = sys.stdin.readline

'''
solved: 2026-
idea:
시간복잡도:
'''
n = int(input())

def find_ways(n) -> int:
  # n이 같은 숫자로만 구성 -> 1 return
  if len(set(list(str(n)))) == 1:
    return 1
  # 아니라면 왼쪽에서 하나 뺀 숫자 + 오른쪽에서 하나 뺀 값 return
  return find_ways(str(n)[:-1]) + find_ways(str(n)[1:])

print(find_ways(n))