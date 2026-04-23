import sys
n = int(input())
words = []
for i in range(n):
    words.append(sys.stdin.readline().strip('\n'))
words = list(set(words))    # 중복 제거

words.sort()                # 알파벳 순 정렬
words.sort(key=lambda words:len(words)) # 길이순 정렬
for i in words:
    print(i)