import sys
n = int(input())
files = dict()
for _ in range(n):
    word = sys.stdin.readline().strip('\n').split('.')
    if word[1] in files:
        files[word[1]] += 1
    else:
        files[word[1]] = 1

files_lst = sorted(list(files.keys()))
for i in files_lst:
    print(i, files[i])