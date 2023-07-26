import sys
from functools import cmp_to_key

def compare(a,b):
    if a[0] > b[0]:
        return 1
    elif a[0] == b[0]:
        return 0
    else:
        return -1


N = int(sys.stdin.readline())
p_list = []

for i in range(N):
    cur_l = list(sys.stdin.readline().split())
    #print(cur_l)
    p_list.append((int(cur_l[0]), cur_l[1]))

#print(p_list)

p_list = sorted(p_list, key=cmp_to_key(compare))

#print(p_list)

for i in p_list:
    print(i[0], i[1])