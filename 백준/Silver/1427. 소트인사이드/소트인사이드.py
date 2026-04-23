n = input()
lst = []
for i in n:
    lst.append(int(i))
lst.sort(reverse = True)
lst = list(map(str, lst))
lst = ''.join(lst)
print(lst)