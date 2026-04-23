import sys
t = int(input())
for _ in range(t):
    words = sys.stdin.readline().strip('\n')
    max = 0
    MSW = '?'
    for i in words:
        if i == ' ':
            continue
        if words.count(i) > max and i != MSW:
            MSW = i
            max = words.count(i)
        elif words.count(i) == max and i != MSW:
            MSW = '?'
    print(MSW)