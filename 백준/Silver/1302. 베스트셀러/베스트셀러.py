import sys
input = sys.stdin.readline

'''
solved: 2026-04-10
idea:
**
1. 책의 제목을 key로, 팔린 횟수를 value로 하는 딕셔너리(Hash Map)를 생성한다.
2. 모든 입력에 대해 딕셔너리의 빈도수를 업데이트한다.
3. 가장 높은 빈도수(max_count)를 찾는다.
4. 빈도수가 max_count와 일치하는 책 제목들을 리스트에 담아 사전 순으로 정렬한다.
5. 정렬된 리스트의 첫 번째 요소를 출력한다.
시간복잡도:
- 입력 및 빈도수 계산: O(N * L) (N은 책의 개수, L은 제목의 평균 길이)
- 최대 빈도수 탐색: O(Unique Books)
- 결과 정렬: O(K log K) (K는 최대 빈도수를 가진 책의 수)
- N이 1,000이므로 매우 넉넉하게 통과 가능하다.
'''

n = int(input())
books = {}

# 1. 빈도수 체크
for _ in range(n):
    title = input().strip()
    if title in books:
        books[title] += 1
    else:
        books[title] = 1

# 2. 최대 빈도수 찾기
max_count = max(books.values())

# 3. 최대 빈도수를 가진 책들을 리스트에 수집
best_sellers = []
for title, count in books.items():
    if count == max_count:
        best_sellers.append(title)

# 4. 사전 순 정렬 후 가장 첫 번째 요소 출력
best_sellers.sort()
print(best_sellers[0])