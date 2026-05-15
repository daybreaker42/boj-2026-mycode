def solution(money):
    if not money:
        return 0
    if len(money) <= 3:
        return max(money)

    n = len(money)

    prev2, prev1 = 0, 0
    for i in range(0, n - 1):
        prev2, prev1 = prev1, max(prev1, prev2 + money[i])
    max_with_first = prev1

    prev2, prev1 = 0, 0
    for i in range(1, n):
        prev2, prev1 = prev1, max(prev1, prev2 + money[i])
    max_without_first = prev1

    return max(max_with_first, max_without_first)