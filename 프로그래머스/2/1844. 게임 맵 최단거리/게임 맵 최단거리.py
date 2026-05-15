import copy
from collections import deque
def solution(maps):
    answer = -1
    n = len(maps)
    m = len(maps[0])
    
    q = deque()
    # x, y
    visited = [[0 for j in range(m)] for i in range(n)]
    q.append((0, 0, visited, 1))
    # q.append((0, 0))
    # maps[y][x] -> (x, y)에 접근 가능!
    while q:
        curr = q.popleft()
        curr_visited = curr[2]
        curr_visited[curr[1]][curr[0]] = 1
        curr_cnt = curr[3]
        # print(f'{curr[0]} {curr[1]}')
        
        if curr[0] == m - 1 and curr[1] == n - 1:
            answer = curr_cnt
            break
        
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx = curr[0] + dx
            ny = curr[1] + dy
            if 0 <= nx < m and 0 <= ny < n and not curr_visited[ny][nx] and maps[ny][nx]:
                curr_visited[ny][nx] = 1
                # new_visited = copy.deepcopy(curr_visited)
                q.append((nx, ny, curr_visited, curr_cnt + 1))
                # curr_visited[ny][nx] = 0
    
    return answer