import sys
m, n = map(int, input().split())
board = []
for i in range(m):
    board.append(sys.stdin.readline().strip('\n'))

checker = 'BW'
min = -1
for i in range(m - 8 + 1):
    for j in range(n - 8 + 1):
        cnt = 0
        
        problem = 0
        for y in range(8):
            for x in range(8):
                if board[i + y][j + x] != checker[(cnt + y)% 2]:
                    problem += 1
                cnt += 1
        if problem > 32:
            problem = 64 - problem
        if min == -1 or min > problem:
            min = problem
print(min)