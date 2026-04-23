import sys
while True:
    word = sys.stdin.readline().strip('\n')
    if word == 'END':
        break
    print(''.join(list(reversed(word))))