import sys
t = int(input())
alphabets = set('ABCDEF')
for i in range(t):
    success = 1
    word = sys.stdin.readline().strip('\n')
    
    # 처음 글자가 alphabets에 없으면 good
    # A가 아닌 다른 alphabets이면 A로 바꿔줌
    if word[0] not in alphabets:
        print('Good')
        continue
    elif word[0] != 'A':
        word = 'A' + word[1:]
    
    # 그 다음에 A가 하나 이상 있어야 하는 규칙, A로만 끝나면 good.
    index = 0
    while word[index] == 'A':
        index += 1
        if index >= len(word):
            success = 0
            break
    # 그 다음에 F가 하나 있어야 하는 규칙, 
    if success and index < len(word) and word[index] == 'F':
        while word[index] == 'F':
            index += 1
            if index >= len(word):
                success = 0
                break
    else:
        success = 0
    # 그 다음에 C가 하나 있어야 하는 규칙
    if success and index < len(word) and word[index] == 'C':
        while word[index] == 'C':
            index += 1
            if index >= len(word):
                break
    else:
        success = 0
    if index < len(word) and word[index] not in alphabets:
        success = 0
    if success == 0:
        print('Good')
        continue
    else:
        print('Infected!')