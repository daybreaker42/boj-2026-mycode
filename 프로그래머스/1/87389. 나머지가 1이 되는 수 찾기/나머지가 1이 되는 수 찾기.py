'''
solved: 2026-05-04
idea: n-1의 1이아닌 가장 작은 약수를 구함
시간복잡도: O(N)
체감난이도: 브2
'''
def solution(n):
    answer = 0
    i = 2
    while i * i <= n - 1:
        if (n - 1) % i == 0:
            answer = i
            break
        i += 1
    if answer == 0:
        answer = n - 1
    return answer