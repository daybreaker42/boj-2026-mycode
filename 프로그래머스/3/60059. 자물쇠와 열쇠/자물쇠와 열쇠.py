def rotate(mat):
    n = len(mat)
    result = [[0 for __ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            result[j][n - 1 - i] = mat[i][j]
    return result

def check(key, lock, dx, dy):
    result = True
    m = len(key)
    n = len(lock)
    # board = [[0 for __ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            xk = j - dx
            yk = i - dy
            if 0 <= xk < m and 0 <= yk < m:
                # print(key[yk][xk], lock[i][j], key[yk][xk] ^ lock[i][j])
                if not key[yk][xk] ^ lock[i][j]:
                    result = False
                    break
            else:
                if not lock[i][j]:
                    result = False
                    break
    return result
    
def solution(key, lock):
    answer = False
    m = len(key)
    n = len(lock)
#     key 시계방향으로 회전시키면서 4번 시도
    for _ in range(4):
        if answer:
            break
        #     가로 방향으로 N + M - 1번
        for dx in range(-(m - 1), n):
            #     세로 방향으로 N + M - 1번 갈 수 있음
            if answer:
                break
            for dy in range(-(m - 1), n):
                if answer:
                    break
                if check(key, lock, dx, dy):
                    answer = True
        
#       key 시계 방향으로 회전
        key = rotate(key)
        
    return answer