answer = 0
def rec(word, lst, cnt):
    global answer
    cnt += 1
    if ''.join(lst) == word:
        answer = cnt
        return cnt

    if len(lst) < 5:
        for ch in 'AEIOU':
            cnt = rec(word, lst + [ch], cnt)
            if answer > 0:
                return cnt

    return cnt

def solution(word):
    global answer    
    rec(word, [], -1)
    return answer