import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))
    queue = deque(arr)
    queue_idx = deque([i for i in range(len(arr))])
    
    cnt = 1
    while queue:

        temp = queue.popleft()
        idx = queue_idx.popleft()
        if len(queue) and temp < max(queue):
            queue.append(temp)
            queue_idx.append(idx)
        else:
            if idx == M:
                print(cnt)    
                break
            else:
                cnt += 1
