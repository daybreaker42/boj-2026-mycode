import sys
aeiou = set(['a', 'e', 'i', 'o', 'u'])
def is_aeiou(k):
    if k in aeiou:
        return 1
    else:
        return 0

while True:
    word = sys.stdin.readline().strip('\n')
    if word == 'end':
        break
    if word.count('a') + word.count('e') + word.count('i') + word.count('o') + word.count('u') == 0:
        print('<%s> is not acceptable.' % word)
        continue
    succeed = 1
    if len(word) > 1:
        if word[0] == word[1] and word[0] != 'e' and word [0] != 'o':
            print('<%s> is not acceptable.' % word)
            continue
    for i in range(len(word)-2):
        if is_aeiou(word[i]) == is_aeiou(word[i+1]) and is_aeiou(word[i+1]) == is_aeiou(word[i+2]):
            succeed = 0
            break
        if word[i+1] == word[i+2] and word[i+1] != 'e' and word[i+1] != 'o':
            succeed = 0
            break
    if succeed == 0:
        print('<%s> is not acceptable.' % word)
        continue
    print('<%s> is acceptable.' % word)