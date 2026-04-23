s = input()
t = input()
success = 1
n = 1
if set(s) - set(t):
    success = 0

if success:
    index_s = 0
    index_t = 0
    while index_s < len(s):
        if t[index_t] == s[index_s]:
            index_s += 1
        if index_s == len(s):
            break
        index_t += 1
        if index_t == len(t):
            n += 1
            index_t = 0
    print(n)
else:
    print(-1)