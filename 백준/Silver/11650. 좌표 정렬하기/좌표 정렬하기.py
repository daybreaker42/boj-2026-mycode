import sys
from operator import attrgetter

n = int(sys.stdin.readline())
coordinates = []
for i in range(n):
    coordinates.append(list(map(int, sys.stdin.readline().split())))

sorted_lst = sorted(coordinates, key = lambda coordinates:(coordinates[0], coordinates[1]))
for i in sorted_lst:
    print(i[0], i[1])