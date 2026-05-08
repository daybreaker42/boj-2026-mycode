import sys
MAX = 1000000007
    
def solution(n, money):
    answer = 0
    length = len(money)
    
    dp = [0] * (n + 1)
    dp[0] = 1
    for idx in range(length):
        for curr in range(money[idx], n + 1):
            dp[curr] += dp[curr - money[idx]]
            dp[curr] %= MAX

    answer = dp[n]
    
    return answer