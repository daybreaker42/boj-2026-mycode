'''
solved: 2026-05-04
idea: 이분탐색으로 a의 팀원보다 큰 b의 최소 팀원을 찾고 출전, 한번출전한 사람은 다시 사용 x
시간복잡도: O(NlogN)~O(N^2)
'''

n = 0
answer = 0
is_available = []
sorted_b = []
# target보다 큰 최소 element의 idx을 정렬된 b 배열에서 반환
def bin_search_available(target, st, ed):
    global is_available, sorted_b, n
    if st == ed:
        if st == n - 1 and sorted_b[st] <= target:
            return -1
        else:
            return st
    mid = (st + ed) // 2
    if sorted_b[mid] > target:
        return bin_search_available(target, st, mid)
    else:
        return bin_search_available(target, mid + 1, ed)

def solution(A, B):
    global is_available, sorted_b, answer, n
    answer = 0
    n = len(A)
#   이미 출전했는지를 표시
    is_available = [True] * n
    sorted_b = sorted(B)
    for target in A:
        idx = bin_search_available(target, 0, n - 1)
        if idx >= 0:
            while idx < n and not is_available[idx]:
                idx += 1
            if idx < n:
                answer += 1
                is_available[idx] = False
        
    
    return answer