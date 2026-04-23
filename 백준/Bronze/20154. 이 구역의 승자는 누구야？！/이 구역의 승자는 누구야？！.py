from collections import deque

s = input()
code = dict(zip([chr(i) for i in range(65, 91)], '32123333113133122212112221'))

lst = deque()
temp_lst = deque()
for i in s:
    lst.append(int(code[i]))

while len(lst) > 1:
    temp = lst.popleft() + lst.popleft()
    temp %= 10
    temp_lst.append(temp)
    if len(lst) <= 1:
        lst.extendleft(temp_lst)
        temp_lst.clear()

if lst[0] % 2 == 1:
    print("I'm a winner!")
else:
    print("You're the winner?")