import sys
from collections import deque

input = sys.stdin.readline

t = int(input())
dx = [2, 2, -2, -2, 1, -1, 1, -1]
dy = [1, -1, 1, -1, 2, 2, -2, -2]

for _ in range(t):
    l = int(input())
    
    graph = [[0]*l for _ in range(l)]
    
    night_x, night_y = map(int, input().split())
    
    graph[night_x][night_y] = 1
    
    target_x, target_y = map(int, input().split())
    
    q = deque()
    q. append([night_x, night_y])
    
    while q:
    
        x, y = q.popleft()
        
        if x == target_x and y == target_y:
            print(graph[x][y] - 1)
            break
        
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < l and 0 <= ny < l and graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                q.append([nx, ny])