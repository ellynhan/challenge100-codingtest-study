import sys
from collections import deque

input = sys.stdin.readline

m, n, h = map(int, input().split())

graph = [list(list(map(int, input().split())) for _ in range(n)) for _ in range(h)]

q = deque()
dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


for i in range(h):
    for j in range(n):
        for k in range(m):
            if graph[i][j][k] == 1:
                q.append([i, j, k])
                
def bfs():
    while q:
        z, x, y = q.popleft()
        
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            
            if nx >= 0 and nx < n and ny >= 0 and ny < m and nz >=0 and nz < h and graph[nz][nx][ny] == 0:
                graph[nz][nx][ny] = graph[z][x][y] + 1
                q.append([nz, nx, ny])

bfs()

z = 1
res = -1

for i in graph:
    for j in i:
        for k in j:
            if k == 0:
                z = 0
                
            res = max(res, k)

if z == 0:
    print(-1)
elif res == 1:
    print(0)
else:
    print(res - 1)