import sys
from collections import deque
input = sys.stdin.readline


def bfs(sx, sy, visited):
    q = deque([(sx, sy)])
    unit = [(sx, sy)]
    visited[sx][sy] = True
    total = graph[sx][sy]
    cnt = 1
    while q:
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                if L <= abs(graph[nx][ny] - graph[x][y]) <= R:
                    visited[nx][ny] = True
                    total += graph[nx][ny]
                    cnt += 1
                    q.append((nx, ny))
                    unit.append((nx, ny))
    
    population = int(total / cnt)
    
    for x, y in unit:
        graph[x][y] = population
    
    if cnt != 1:
        return 1
    else:
        return 0
    
def bfsAll():
    global day
    while True:
        flag = 0
        visited = [[False]*N for _ in range(N)]
        flag = False
        for i in range(N):
            for j in range(N):
                if not visited[i][j]:
                    flag += bfs(i, j, visited)
                    
        if flag == 0:
            break
        
        day += 1

N, L, R = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

day = 0
bfsAll()
print(day)
