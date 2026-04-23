import sys, math
def gcd(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

n = int(input())
lst = []
diff = []
ans = []
for i in range(n):
    lst.append(int(sys.stdin.readline()))
lst.sort()
#print(lst)

for i in range(n-1):
    diff.append(lst[i+1]-lst[i])

if n > 2:
    GCD = gcd(diff[0], diff[1])
else:
    GCD = diff[0]
#print(diff)

for i in range(2, n-1):
    GCD = gcd(GCD, diff[i])

for i in range(2, int(GCD**0.5)+1):
    if GCD % i == 0:
        ans.append(i)
        if i != GCD//i:
            ans.append(GCD//i)
ans.sort()
ans.append(GCD)
print(' '.join(map(str, ans)))
#print(GCD, ans, diff)