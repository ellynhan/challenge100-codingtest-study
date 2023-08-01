import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

dx = [-2, -2, 0, 0, 2, 2]
dy = [-1, 1, -2, 2, -1, 1]

N = int(input())
arr = [ [0 for _ in range(N)] for _ in range(N)]
r1, c1, r2, c2 = map(int, input().split())
visited = [ [0 for _ in range(N)] for _ in range(N)]
queue = deque()

queue.append((r1,c1))

while queue:
    x, y = queue.popleft()
 
    for i in range(6):
        cx = x + dx[i]
        cy = y + dy[i]
        if 0<= cx < N and 0<= cy < N:
            if visited[cx][cy] == 0:
                visited[cx][cy] = visited[x][y] + 1
                queue.append((cx,cy))

# for i in range(N):
#     print(visited[i])

if visited[r2][c2] == 0:
    print(-1)
else:    
    print(visited[r2][c2])
