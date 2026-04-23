# 하노이의 탑 이동 횟수, 과정 출력하는 프로그램
def hanoi(n, a, b):
    if n == 1:
        print(a, b)
        return
    else:
        arr = []
        arr.extend([a, b])
        notin = [x for x in range(1, 4) if x not in arr]
        hanoi(n-1, a, notin[0]) # ILovePython
        print(a, b)             # IDEA
        hanoi(n-1, notin[0], b)
        return

n = int(input())
print(2**n - 1)
hanoi(n, 1, 3)