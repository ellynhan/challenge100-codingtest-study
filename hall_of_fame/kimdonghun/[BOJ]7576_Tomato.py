import sys
from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

graph = []
q = deque()

M,N = map(int, sys.stdin.readline().split())

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))
    

#print(*graph, sep="\n")

def bfs(graph):
    global q
    #q.append((x,y))

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue

            if graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                q.append((nx, ny))

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            q.append((j, i))

#bfs(graph, 0, 0)
#print(max(graph))
#print(*graph, sep="\n")

bfs(graph)
#print(*graph, sep="\n")

maxNum = -1
is_not_ripen = False
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            is_not_ripen = True
        if maxNum < graph[i][j]:
            maxNum = graph[i][j]

if is_not_ripen or maxNum == -1:
    print(-1)
elif maxNum == 1:
    print(0)
else:
    print(maxNum - 1)
