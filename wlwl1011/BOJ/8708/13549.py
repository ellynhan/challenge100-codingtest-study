import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque


N, K = map(int, input().split())
queue = deque()
queue.append(N)
visited = [-1] * 100001
visited[N] = 0

while queue:
    time = queue.popleft()
    if time == K:
        break
    if 0 <= time-1 < 100001 and visited[time-1] == -1:    
        visited[time-1] = visited[time]+1
        queue.append(time-1)
    if 0 <= time*2 < 100001 and visited[time*2] == -1:
        visited[time*2] = visited[time]
        queue.append(time*2)
    if 0 <= time+1 < 100001 and visited[time+1] == -1:    
        visited[time+1] = visited[time]+1
        queue.append(time+1)
 
        
print(visited[time])


