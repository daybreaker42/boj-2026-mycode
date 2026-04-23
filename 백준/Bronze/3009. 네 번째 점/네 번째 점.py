# 직사각형의 네 점 좌표를 완성하는 문제
import sys
xs = []
ys = []
for i in range(3):
    x, y = list(map(int, sys.stdin.readline().split()))
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()
answer = [0, 0]
for i in range(3):
    if xs.count(xs[i]) == 1:
        answer[0] = xs[i]  
    if ys.count(ys[i]) == 1:
        answer[1] = ys[i]

print(answer[0], answer[1])