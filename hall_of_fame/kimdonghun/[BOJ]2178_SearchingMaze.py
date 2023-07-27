import sys
from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

graph = []
N, M = map(int, sys.stdin.readline().split())
for i in range(N):
    graph.append(list(map(int, sys.stdin.readline()[:-1])))

#print(graph)
#print(*graph, sep="\n")
visited = [[False for _ in range(M)] for _ in range(N)]

def bfs(x, y):
    q = deque()
    q.append((x,y))
    #graph[y][x] = 1
    visited[y][x] = True

    while q:
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue

            if graph[ny][nx] == 1 and visited[ny][nx] == False:
                visited[ny][nx] = True
                graph[ny][nx] = graph[y][x] + 1
                q.append((nx, ny))

bfs(0,0)
#print(*graph, sep="\n")
print(graph[N-1][M-1])
