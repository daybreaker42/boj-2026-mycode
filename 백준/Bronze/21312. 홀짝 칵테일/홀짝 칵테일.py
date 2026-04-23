a, b, c = map(int, input().split())
odd_res = 1
even_res = 1
cnt = 0
for i in [a, b, c]:
    if i % 2 == 1:
        odd_res *= i
        cnt += 1
    else:
        even_res *= i

if cnt == 0:
    print(even_res)
else:
    print(odd_res)