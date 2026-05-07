'''
solved: 2026-
idea: 생각해보면 점수를 얻거나(어피치+1개) 안얻거나(0개소모) 둘 중 하나
시간복잡도:
'''
score_diff = 0
answer = []
apeach = []

def rec(lst, idx, n):
    global answer, apeach, score_diff
    if idx < 0:
#         계산 후 ans판단 후 return
        my_score = 0
        apeach_score = 0
        for i in range(11):
            if lst[i] > apeach[i]:
                my_score += 10 - i
            elif lst[i] < apeach[i]:
                apeach_score += 10 - i
            elif apeach[i] > 0:
                apeach_score += 10 - i
        current_score_diff = my_score - apeach_score
        
        if current_score_diff > score_diff:
            answer = lst
            score_diff = current_score_diff
        # print(lst)
        # print(my_score, apeach_score)
        return

#     해당 숫자 쏠건지 말건지 둘 다 try - 각 경우 화살 제거하고 다음 호출
    total = sum(lst)
    for i in range(apeach[idx] + 1, -1, -1):
        if total + i <= n:
            tmp_lst = lst.copy()
            tmp_lst[idx] = i
            rec(tmp_lst, idx - 1, n)
    return
    

def solution(n, info):
    global answer, apeach
    apeach = info
    rec([0] * 11, 10, n)
    if not answer:
        answer = [-1]
    
    return answer