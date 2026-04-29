from collections import deque
def solution(s):
    answer = True
    bracket_stack = deque()
    for ch in s:
        if ch == '(':
            bracket_stack.append(ch)
        else:
#           ) 입력시
            if not bracket_stack:
#               stack 비어있다면 false
                answer = False
                break
            else:      
                if bracket_stack[-1] == '(':
#                   stack 마지막 값이 (이면 정상적으로 pop
                    bracket_stack.pop()
                else:
#                   아니면 false
                    answer = False
                    break
    if bracket_stack:
        answer = False
    return answer