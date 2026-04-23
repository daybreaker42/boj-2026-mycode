import sys
s = sys.stdin.readline().strip('\n')
lst_s = list(map(str, s))

index = 0
start = 0
word = []
while index < len(s):
    if lst_s[index] == '<':
        while lst_s[index] != '>':
            index += 1
    elif lst_s[index] != ' ':
        start = index
        while lst_s[index] != ' ' and lst_s[index] != '<':
            word.append(s[index])
            index += 1
            if index == len(s):
                break
        lst_s[start:index] = word[::-1]
        start = 0
        word = []
        if index < len(s) and lst_s[index] == '<':
            index -= 1
    index += 1
print(''.join(lst_s))