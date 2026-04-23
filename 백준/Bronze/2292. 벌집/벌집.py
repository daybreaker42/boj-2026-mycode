# 육각형 벌집의 n번째 방에 가려면 몇 개의 방을 지나야 하는지 구하는 프로그램
n = int(input())
n = (n-1)/6
i = 0
while 0.5 * (i**2 - i) < n :
    i += 1
if i > 0:
    print(i)
else:
    print(1)