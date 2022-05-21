import sys
from collections import deque

dx = [-1, 0, 1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

M, N, H = map(int, sys.stdin.readline().split())
graph = []
h_graph = []
q = deque()

for i in range(H):
    for j in range(N):
        h_graph.append(list(map(int, sys.stdin.readline().split())))
        
        for k in range(M):
            if h_graph[j][k] == 1:
                q.append((k,j,i))
    
    graph.append(h_graph)
    h_graph = []

#print(q)

def bfs(graph):
    while q:
        x,y,z = q.popleft()

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H:
                continue

            if graph[nz][ny][nx] == 0:
                graph[nz][ny][nx] = graph[z][y][x] + 1
                q.append((nx,ny,nz))

bfs(graph)

#print(*graph, sep = "\n")

is_not_ripen = False
max_num = -1

for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 0:
                is_not_ripen = True

            if graph[i][j][k] > max_num:
                max_num = graph[i][j][k]

if is_not_ripen or max_num == -1:
    print(-1)
else:
    print(max_num - 1)
