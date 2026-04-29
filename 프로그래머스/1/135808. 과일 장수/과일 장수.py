def solution(k, m, score):
    answer = 0
    score.sort()
    
    offset = len(score) % m
    for i in range(len(score) // m):
        answer += score[i * m + offset] * m
    
    return answer