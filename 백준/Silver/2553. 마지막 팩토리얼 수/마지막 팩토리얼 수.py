import math
n = int(input())
for i in reversed(str(math.factorial(n))):
    if i != '0':
        print(i)
        break