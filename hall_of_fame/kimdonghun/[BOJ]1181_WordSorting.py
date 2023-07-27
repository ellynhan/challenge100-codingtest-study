import functools
import sys
from functools import cmp_to_key

def compare(a,b):
    if len(a) > len(b):
        return 1
    elif len(a) == len(b):
        if a > b :
            return 1
        elif a == b :
            return 0
        else :
            return -1
    else :
        return -1

N = int(sys.stdin.readline())

w_list = []

for i in range(N):
    word = sys.stdin.readline()[:-1]
    w_list.append(word)

w_set = set(w_list)
w_set = sorted(w_set, key=cmp_to_key(compare))

for i in w_set:
    print(i)