a, b, c = input().split()
a, b, c = int(a), int(b), int(c)
list_a = [a, b, c]
list_a.remove(max(a, max(b, c)))
sec = max(list_a[0], list_a[1])
print(sec)