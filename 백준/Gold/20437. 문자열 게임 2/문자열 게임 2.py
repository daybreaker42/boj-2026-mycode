import sys
t = int(input())
for _ in range(t):
    cnt = 0
    w = sys.stdin.readline().strip('\n')
    k = int(sys.stdin.readline().strip('\n'))
    MIN = len(w)
    MAX = 0
    location = dict(zip((chr(i) for i in range(ord('a'), ord('z')+1)), ([] for i in range(26))))
    for i, word in enumerate(w):
        location[word].append(i)
    for i in location:
        if len(location[i]) >= k:
            cnt = 1
            for j in range(len(location[i]) - k + 1):
                if MIN > location[i][j+k-1] - location[i][j]:
                    MIN = location[i][j+k-1] - location[i][j]
                if MAX < location[i][j+k-1] - location[i][j]:
                    MAX = location[i][j+k-1] - location[i][j]
    if cnt == 0:
        print(-1)
    else:
        print(MIN+1, MAX+1)