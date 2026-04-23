import copy
n = int(input())
res = [0] + [1] * 9
p_res = []
for i in range(n-1):
    p_res = copy.copy(res)
    res = [0] * 10
    for j in range(10):
        if j > 0:
            res[j] += p_res[j-1]
        if j < 9:
            res[j] += p_res[j+1]
print(sum(res) % 1000000000)