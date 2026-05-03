def get_collatz(n):
    if n == 1:
        return 0
    
    if n % 2 == 0:
        return 1 + get_collatz(n // 2)
    else:
        return 1 + get_collatz(3 * n + 1)

def solution(num):
    answer = 0
    answer = get_collatz(num)
    if answer > 500:
        answer = -1
    return answer