answer = []
def move(num, source, dest):
    global answer
    if num == 1:
        answer.append([source, dest])
        return
#   아닌 경우
    left = 6 - (source + dest)  # 1, 2, 3 합이 6 -> 남은 1개 찾으려면 6에서 빼면 됨
    
    move(num - 1, source, left)
    # answer.append([source, left])
    
    move(1, source, dest)
    # answer.append([source, dest])
    
    move(num - 1, left, dest)
    # answer.append([left, dest])
    return
        
def solution(n):
    global answer
    move(n, 1, 3)
    
    return answer