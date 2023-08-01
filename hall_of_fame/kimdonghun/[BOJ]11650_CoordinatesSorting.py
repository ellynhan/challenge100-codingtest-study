import sys
from functools import cmp_to_key

def compare(a, b):
    if a[0] > b[0]:
        return 1
    elif a[0] == b[0]:
        if a[1] > b[1]:
            return 1
        elif a[1] < b[1]:
            return -1
        else:
            return 0
    else:
        return -1

N = int(sys.stdin.readline())
sort_l = []

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    sort_l.append((x,y))

#print(sort_l)

#sort_l = sorted(sort_l, key=cmp_to_key(compare))
sort_l = sorted(sort_l, key=lambda x: (x[0], x[1]))

#print(sort_l)

for i in sort_l:
    print(i[0], i[1])