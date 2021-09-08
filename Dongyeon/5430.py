# 백준 5430 AC
# 골드 5
from collections import deque
import sys

T = int(sys.stdin.readline())
for _ in range(T):
    func = sys.stdin.readline().replace('\n', '')
    n = int(sys.stdin.readline())
    q = deque(sys.stdin.readline().replace('[', '').replace(']', '').split(','))

    if q[0] == '\n' :
        q = []
    q = deque(map(int, q))

    tmpl = func.split('R')
    rev = len(tmpl) - 1
    countl = 0
    countr = 0
    lr = 1
    for i in range(len(tmpl)):
        if lr:
            countl += len(tmpl[i])
            lr = 1-lr
        else:
            countr += len(tmpl[i])
            lr = 1-lr

    try:
        for _ in range(countl):
            q.popleft()
        for _ in range(countr):
            q.pop()
        if rev%2 == 1:
            q.reverse()
        print('['+','.join(list(map(str, list(q))))+']')
    except:
        print('error')
