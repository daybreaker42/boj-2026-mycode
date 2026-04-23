from itertools import combinations
n = int(input())
max_result = 0
min_result = -1

def tenth(num):
    res = num // 10 + num % 10
    return res

def hundredth(num, c1, c2):
    return int(str(num)[:c1]) + int(str(num)[c1:c2]) + int(str(num)[c2:])

def find_odd(num, max):
    global max_result
    global min_result
    temp = 0
    for i in str(num):
        if int(i) % 2 == 1:
            max += 1
    if len(str(num)) > 2:
        for i in combinations(range(1, len(str(num))), 2):
            temp = hundredth(num, i[0], i[1])
            find_odd(temp, max)
    elif len(str(num)) == 2:
        temp = tenth(num)
        find_odd(temp, max)
    else:
        if max > max_result:
            max_result = max
        if min_result > max or min_result < 0:
            min_result = max
    return

find_odd(n, 0)
print(min_result, max_result)