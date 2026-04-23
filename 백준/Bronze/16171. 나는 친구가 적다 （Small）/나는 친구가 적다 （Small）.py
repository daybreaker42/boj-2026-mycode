import sys
word = sys.stdin.readline().strip('\n')
find = sys.stdin.readline().strip('\n')

numbers = set('0123456789')
parsed_word = []
for i in word:
    if i in numbers:
        continue
    parsed_word.append(i)
parsed_word = ''.join(parsed_word)

if find in parsed_word:
    print(1)
else:
    print(0)