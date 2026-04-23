import sys
from collections import deque
try:
    while 1:
        s, t = sys.stdin.readline().split()
        lst_s = ''.join(s)
        lst_t = ''.join(t)
        lst_s = deque(lst_s)
        
        for i in lst_t:
            if i == lst_s[0]:
                lst_s.popleft()
                if len(lst_s) == 0:
                    break
        if lst_s == deque():
            print('Yes')
        else:
            print('No')
except:
    exit()