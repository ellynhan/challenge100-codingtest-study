import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque


N, K = map(int, input().split())
queue = deque()
queue.append((N,0))

while queue:
    time, cnt = queue.popleft()
    if time == K:
        print(cnt)
        break
    queue.append((time*2, cnt))
    queue.append((time+1, cnt+1))
    queue.append((time-1, cnt+1))
       



