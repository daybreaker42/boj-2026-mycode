parent = []

def union(v1, v2):
    global parent
    r_v1 = find(v1)
    r_v2 = find(v2)
    
    if r_v1 < r_v2:
        parent[r_v2] = r_v1
    elif r_v1 > r_v2:
        parent[r_v1] = r_v2
    
    return

def find(v1):
    global parent
    if v1 == parent[v1]:
        return v1
    parent[v1] = find(parent[v1])
    return parent[v1]

def solution(n, computers):
    global parent
    answer = 0
    parent = [i for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            if computers[i][j]:
                union(i, j)
                
    # for i in range(n):
    #     print(parent[i])
    
    for i in range(n):
        if i == parent[i]:
            answer += 1
    
    return answer