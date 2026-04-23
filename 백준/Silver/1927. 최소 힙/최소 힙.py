import sys
import heapq

input = sys.stdin.readline

'''
solved: 2026-04-10
idea: 최소 힙 사용
'''

n = int(input())
max_heap = []

for _ in range(n):
    x = int(input())
    
    if x == 0:
        if not max_heap:
            print(0)
        else:
            # 음수로 저장된 값을 다시 양수로 변환하여 출력 (가장 큰 값)
            print(heapq.heappop(max_heap))
    else:
        # 최대 힙을 위해 음수로 push
        heapq.heappush(max_heap, x)