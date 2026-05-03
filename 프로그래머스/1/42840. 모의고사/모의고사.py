def solution(answers):
    answer = []
    math_giveup = [
        [1, 2, 3, 4, 5],
        [2, 1, 2, 3, 2, 4, 2, 5],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]
    point_lst = []
    for i in range(3):
#       각 사람마다 반복
        point = 0
        length = len(math_giveup[i])
        for j in range(len(answers)):
#           찍은 답이랑 정답이랑 일치하는지 판별
            if answers[j] == math_giveup[i][j % length]:
                point += 1
        point_lst.append(point)
        
    max_point = max(point_lst)
    for i in range(3):
        if point_lst[i] == max_point:
            answer.append(i + 1)
            
    return answer