import sys
from functools import cmp_to_key

def compare(a,b):
    if a[1] > b[1]:
        return 1
    elif a[1] == b[1]:
        if a[0] > b[0]:
            return 1
        elif a[0] < b[0]:
            return -1
        else:
            return 0
    else:
        return -1

N = int(sys.stdin.readline())

n_list = []

for i in range(N):
    x,y = map(int, sys.stdin.readline().split())
    n_list.append((x,y))

#n_list = sorted(n_list, key=lambda x:(x[1],x[0]))
n_list = sorted(n_list, key=cmp_to_key(compare))

#print(n_list)
for i in n_list:
    print(i[0], i[1])