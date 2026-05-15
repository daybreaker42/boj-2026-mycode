'''
27 -> 55 / ((5+5)/5)
+ -(전체만 한다고 가정, 마지막에만 뺄셈시 / 0이 될수도?) *(전체, 마지막것만) /(전체에, 마지막것만) *10+N하기(마지막거에만)

2)
dp[i] 가 i를 만들기 위한 방법을 저장한다면? 그리고 탑다운으로 해결한다면?
-> 대신 배열이 n*number만큼 필요
ㄴ대신에 배열을 넘어갈 경우 (나누기면 계속 *n씩 증가하므로)을 고려, 배열의 최대크기를 어떻게 설정할건지도 문제임
'''
import sys
from collections import deque
MAX = 10000000
INF = 100000000
sys.setrecursionlimit(1000000)
# dp = []

def solution(N, number):
    # global dp
    n = N
    answer = -1
    dp = [set() for i in range(9)]
    dp[1] = {n}
    if number in dp[1]:
        return 1
    
    for i in range(2, 9):
        # print(f'>> {i}')
        dp[i].add(int(f'{n}' * i))
        for j in range(1, i):
            s1_idx = j
            s2_idx = i - j
            # print(f'>> {s1_idx} {s2_idx}')
            for s1_ele in dp[s1_idx]:
                for s2_ele in dp[s2_idx]:
                    # if s1_ele + s2_ele == n:
                    #     print(f'{s1_ele} + {s2_ele}')
                    dp[i].add(s1_ele + s2_ele)
                    
                    dp[i].add(s1_ele - s2_ele)
                    dp[i].add(s1_ele * s2_ele)
                    if s2_ele > 0:
                        dp[i].add(int(s1_ele / s2_ele))

        if number in dp[i]:
            answer = i
            break
    # print(dp)
    # for i in range(9):
    #     print(dp[i])
    return answer