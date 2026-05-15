visited = []
answer = 0
def dfs(st, n, computers, first):
    global answer, visited
    if visited[st]:
        return
    
    visited[st] = 1
    for i in range(n):
        if computers[st][i] and not visited[i]:
            dfs(i, n, computers, 0)
            
    if first:
        answer += 1
    return

def solution(n, computers):
    global answer, visited
    visited = [0 for i in range(n)]
    
    for i in range(n):
        dfs(i, n, computers, 1)
    
    return answer