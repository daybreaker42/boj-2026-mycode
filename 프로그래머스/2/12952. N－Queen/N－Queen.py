'''
solved: 2026-05-01
idea:
1. queen이 있는지 체크할때 모든 board을 돌면서 N^2으로 체크할 필요 없이, row_check, col_check, diag check 등으로 빠르게 확인 가능.
2. 각 row별로 queen은 반드시 하나 존재함. -> for으로 row 돌 필요 없음. 남은 queen 개수 = 남은 row 개수
3. diagonal 개수 = 2 * n - 1개, 그리고 합이 일정한거랑 차가 일정한거 사용하면 각 diagnol별로 배치 가능.
시간복잡도:
'''


answer = 0
row_check = []
col_check = []
diag_add_check = []
diag_sub_check = []

def check_place(i, j, n):
    # global row_check, col_check, diag_add_check, diag_sub_check
    if row_check[i] or col_check[j] or diag_add_check[i + j] or diag_sub_check[i - j + n - 1]:
        return False
    return True

def place_queen(n, i, j):
    global answer, row_check, col_check, diag_add_check, diag_sub_check
    if i == n:
        answer += 1
        return;
#   퀸 배치 가능한지 확인 (대각선, 행, 열에 겹치는거 확인) num을 1 줄이고, 현재 좌표에 퀸을 배치, i, j을 다음 좌표로 이동시킨 함수를 호출, 이를 이후 모든 좌표들에 대해 반복
    
    for new_j in range(n):
        if check_place(i, new_j, n):
            row_check[i] = True
            col_check[new_j] = True
            diag_add_check[i + new_j] = True
            diag_sub_check[i - new_j + n - 1] = True
#                   다음 queen placement
            place_queen(n, i + 1, new_j)
            row_check[i] = False
            col_check[new_j] = False
            diag_add_check[i + new_j] = False
            diag_sub_check[i - new_j + n - 1] = False
        
    return
        

def solution(n):
    global answer, row_check, col_check, diag_add_check, diag_sub_check
    
#   board init
    row_check = [False for i in range(n)]
    col_check = [False for i in range(n)]
    diag_add_check = [False for i in range(2 * n - 1)]
    diag_sub_check = [False for i in range(2 * n - 1)]

#   재귀 -> queen 배치
    place_queen(n, 0, 0)
    
    return answer

# print(solution(4))