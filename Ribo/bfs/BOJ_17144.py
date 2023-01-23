import sys
from copy import deepcopy
input = sys.stdin.readline

def bfs():
    temp = [[0]*c for _ in range(r)]
    for x in range(r):
        for y in range(c):
            if graph[x][y] != 0 and graph[x][y] != -1:
                total = 0
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    
                    if nx < 0 or ny < 0 or nx >= r or ny >= c: continue
                    if graph[nx][ny] == -1: continue
                    temp[nx][ny] += graph[x][y] // 5
                    total += graph[x][y] // 5
                graph[x][y] -= total
    
    for i in range(r):
        for j in range(c):
            graph[i][j] += temp[i][j]
            
def ccw():
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]
    dir = 0
    before = 0
    x, y = up, 1
    while True:
        nx = x + dx[dir]
        ny = y + dy[dir]
        if x == up and y == 0:
            break
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            dir += 1
            continue
        graph[x][y], before = before, graph[x][y]
        x = nx
        y = ny

def cw():
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    dir = 0
    before = 0
    x, y = down, 1
    while True:
        nx = x + dx[dir]
        ny = y + dy[dir]
        if x == down and y == 0:
            break
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            dir += 1
            continue
        graph[x][y], before = before, graph[x][y]
        x = nx
        y = ny


r, c, t = map(int, input().split())
graph = []
cleaner = []
for i in range(r):
    graph.append(list(map(int, input().split())))
    for j in range(c):
        if graph[i][j] == -1:
            cleaner.append(i)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
    
up, down = cleaner[0], cleaner[1]
for _ in range(t):
    bfs()
    ccw()
    cw()

ans = 0
for i in range(r):
    for j in range(c):
        if graph[i][j] > 0:
            ans += graph[i][j]

print(ans)
