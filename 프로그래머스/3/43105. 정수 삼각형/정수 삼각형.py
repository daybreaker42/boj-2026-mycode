'''
solved: 2026-
idea: 위에서부터 바텀업
시간복잡도:
'''

def solution(triangle):
    answer = 0
    height = len(triangle)
    
    dp = triangle
    # print(dp)
    
    for h in range(1, height):
        for i in range(h + 1):
            if i == 0:
                dp[h][i] += dp[h - 1][i]
            elif i == h:
                dp[h][i] += dp[h - 1][i - 1]
            else:
                left = dp[h - 1][i - 1]
                right = dp[h - 1][i]
                if left > right:
                    dp[h][i] += dp[h - 1][i - 1]
                else:
                    dp[h][i] += dp[h - 1][i]
            answer = max(answer, dp[h][i])
                
    return answer