import sys
input = sys.stdin.readline

'''
solved: 2026-04-10
idea:
1. 이름과 상태(enter/leave)가 주어질 때, 'enter'면 집합에 추가하고 'leave'면 집합에서 제거한다.
2. Python의 set 자료구조는 내부적으로 해시 테이블을 사용하므로 추가/삭제 연산이 평균 O(1)이다.
3. 최종적으로 집합에 남아있는 이름을 리스트로 변환한 뒤, 사전 순의 역순(내림차순)으로 정렬한다.
시간복잡도:
- 입력 및 집합 연산: O(n) (n <= 1,000,000)
- 결과 리스트 정렬: O(k log k) (k는 현재 회사에 있는 사람 수, k <= n)
- 전체 시간복잡도: O(n log n) 이내로, 1초 제한을 충분히 통과한다.
'''

n = int(input())
in_office = set()

for _ in range(n):
    # 이름과 액션을 분리하여 입력받음
    name, action = input().split()
    
    if action == 'enter':
        in_office.add(name)
    else:
        # action == 'leave'인 경우
        # discard는 원소가 없어도 에러를 발생시키지 않음 (remove보다 안전)
        in_office.discard(name)

# 집합을 리스트로 변환 후 내림차순 정렬
result = sorted(list(in_office), reverse=True)

# 한 줄에 하나씩 이름 출력
for name in result:
    print(name)