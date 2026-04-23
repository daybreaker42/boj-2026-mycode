lst = []
lst = list(map(int, input().split()))

res = 0
for i in range(5):
    res += lst[i] * lst[i]
res %= 10
print(res)