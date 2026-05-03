def to_triple(n: int) -> str:
#     10 -> 3
    str_n = str(n)
    ans = 0
    exp = 1
    idx = 0
    while exp <= n:
        exp *= 3
        idx += 1
        
    idx -= 1
    exp //= 3
    length = idx + 1
    lst = [0] * length
    while idx >= 0:
        if exp <= n:
            lst[length - idx - 1] = n // exp
            n %= exp
        idx -= 1
        exp //= 3
    ans = ''.join(map(str, lst))
    return ans

def to_deca(n: str) -> int:
#     3 -> 10
    ans = 0
    exp = 1
    for ch in n[::-1]:
        ans += int(ch) * exp
        exp *= 3
    return ans

def solution(n):
    answer = 0
    if n < 3:
        return n
    answer = to_deca(to_triple(n)[::-1])
    
    return answer