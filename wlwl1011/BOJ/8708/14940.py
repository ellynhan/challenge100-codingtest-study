import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

queue = deque()
N, M = map(int, input().split())
arr = [[0 for _ in range(M)] for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

destination_x = 0
destination_y = 0

for i in range(N):
    arr[i] = list(map(int, input().split()))
    for j in range(M):
        if arr[i][j] == 2:
            destination_x = i
            destination_y = j
            queue.append((i,j))

while queue:
    x, y = queue.popleft()
    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]
        if 0 <= tx < N and 0 <= ty < M:
            if arr[tx][ty] == 1: #갈 수 있는 땅이면
                if not visited[tx][ty] :
                    visited[tx][ty] = visited[x][y] + 1
                    queue.append((tx,ty))

for i in range(N):
    for j in range(M):
        if visited[i][j] == 0 and arr[i][j] == 1:
            print(-1,end=' ')         
            continue
        print(visited[i][j], end=' ')  
    print()             



