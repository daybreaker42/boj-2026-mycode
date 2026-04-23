# Fly me to the Alpha Centauri
import sys

num = int(input())
for i in range(num):
    a, b = list(map(int, sys.stdin.readline().split()))
    distance = b - a
    n = 1
    while n**2 <= distance:
        n += 1
    n -= 1  # n**2 < distance < (n+1)**2 로 만들어주는 수식
    
    if n**2 == distance:
        print(2*n-1)
    else:
        remain = distance - n**2
        if remain <= n:
            print(2*n)
        else:
            print(2*n + 1)