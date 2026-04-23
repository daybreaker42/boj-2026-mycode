import sys

n = int(input())
people = []
for i in range(n):
    people.append((list(map(int, sys.stdin.readline().split()))))

bigger = [0] * n
for i in range(n):
    for j in range(n):
        if i != j:
            if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
                bigger[i] += 1

for i in bigger:
    print(i + 1, end = ' ')