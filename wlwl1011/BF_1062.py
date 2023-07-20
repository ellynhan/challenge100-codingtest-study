import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))


N, K = map(int, input().split())

if K < 5 :
    print(0)
elif K == 26:
    print(N)
else:    
    answer = 0
    words = [set(input()).difference('a', 'c', 'i', 't', 'n') for _ in range(N)]
    learn = [0] * 26
    
    for c in ('a', 'c', 'i', 'n', 't'):
        learn[ord('c')-ord('a')] = 1

    def dfs(idx, cnt):
        global answer

        if cnt == K - 5:
            readcnt = 0
            for word in words:
                check = True
                for w in word:
                    if not learn[ord(w) - ord('a')]:
                        check = False
                        break
                if check:
                    readcnt += 1
            answer = max(answer, readcnt)
            return

        for i in range(idx, 26):
            if not learn[i]:
                learn[i] = True
                dfs(i, cnt + 1)
                learn[i] = False                       
    dfs(0, 0)
    print(answer)
            