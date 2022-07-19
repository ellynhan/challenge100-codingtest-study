import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [list(map(int, input().rstrip())) for _ in range(n)]
q = deque()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q.append([0,0])


def bfs():
    while q:
        x,y = q.popleft()
        
        if x == n-1 and y == m-1:
            print(graph[x][y])
            break
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0<= ny < m and graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                q.append([nx, ny])
        


bfs()