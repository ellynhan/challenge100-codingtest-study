import sys
from collections import deque
input = sys.stdin.readline


def turn(d):
    up = dice[1]
    if d == 1:
        dice[1] = dice[4]
        dice[4] = dice[6]
        dice[6] = dice[3]
        dice[3] = up
    elif d == 2:
        dice[1] = dice[3]
        dice[3] = dice[6]
        dice[6] = dice[4]
        dice[4] = up
    elif d == 3:
        dice[1] = dice[5]
        dice[5] = dice[6]
        dice[6] = dice[2]
        dice[2] = up
    else:
        dice[1] = dice[2]
        dice[2] = dice[6]
        dice[6] = dice[5]
        dice[5] = up
    print(dice[1])
    
def move(x, y):
    while dir:
        d = dir.popleft()
        nx = x + dx[d-1]
        ny = y + dy[d-1]
        if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
        turn(d)
        if graph[nx][ny] == 0:
            graph[nx][ny] = dice[6]
        else:
            dice[6] = graph[nx][ny]
            graph[nx][ny] = 0
        
        x, y = nx, ny
        

n, m, x, y, k = map(int, input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

dir = list(map(int, input().split()))
dir = deque(dir)

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

dice = [0]*7

move(x, y)
