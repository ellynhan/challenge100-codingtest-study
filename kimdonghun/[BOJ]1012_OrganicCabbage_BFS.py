import sys
from collections import deque

T = int(sys.stdin.readline())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs(graph, x, y):
    q = deque()
    q.append((x,y))
    graph[y][x] = 0

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue

            if graph[ny][nx] == 1:
                graph[ny][nx] = 0
                q.append((nx, ny))
                
for i in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    graph = [[0 for _ in range(M)] for _ in range(N)]
    
    for j in range(K):
        X, Y = map(int, sys.stdin.readline().split())

        graph[Y][X] = 1

    #print(graph)

    res_cnt = 0

    #print(*graph, sep="\n")

    for y in range(N):
        for x in range(M):
            #print("**", x, y)
            if graph[y][x] == 1:
                bfs(graph, x, y)
                #print(*graph, sep="\n")
                res_cnt += 1 
                #print("==", x, y)
                #print(res_cnt)      

    print(res_cnt)

    #print(*graph, sep="\n") 
