import sys
from collections import deque

input = sys.stdin.readline

    


m, n = map(int, input().split())

graph = []
q = deque([])
res = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(n):
    graph.append(list(map(int, input().split())))
    
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            q.append([i,j])
            

def bfs():
    while q:
        x, y = q.popleft()
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            if nx >= 0 and nx < n and ny >= 0 and ny < m and graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                q.append([nx, ny])

bfs()
        
for i in graph:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)

    res = max(res, max(i))

print(res -1)