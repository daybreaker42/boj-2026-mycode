n = int(input())
lst = sorted(list(map(int, input().split())))
print(lst[0] * lst[-1])