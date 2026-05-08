def solution(m, n, puddles):
    MAX = 1000000007
    answer = 0
    dp = [[0 for __ in range(m)] for _ in range(n)]
    dp[0][0] = 1
    
    for puddle in puddles:
        x, y = puddle
        x -= 1
        y -=1
        dp[y][x] = -1
    
    for i in range(n):
        for j in range(m):
            if dp[i][j] >= 0:
                if j < m - 1 and dp[i][j + 1] >= 0:
                    dp[i][j + 1] += dp[i][j]
                    dp[i][j + 1] %= MAX
                if i < n - 1 and dp[i + 1][j] >= 0:
                    dp[i + 1][j] += dp[i][j]
                    dp[i + 1][j] %= MAX
    answer = dp[n - 1][m - 1]
    return answer