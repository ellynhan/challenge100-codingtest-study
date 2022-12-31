import sys
from collections import deque
input = sys.stdin.readline

def turn(i, d):
    if d == 'L':
        i = (i+1)%4
    if d == 'D':
        i = (i-1)%4
    
    return i

def move():
    x, y = 1, 1
    i = 0
    cnt = 0
    snake = deque([(1, 1)])
    while True:
        x += dx[i]
        y += dy[i]
        cnt += 1
        if x <= 0 or x > n or y <= 0 or y > n: break
        if (x, y) in snake: break
        snake.append((x, y))
        
        if graph[x][y] == 1:
            graph[x][y] = 0 
        else:
            snake.popleft()
        
        if cnt in dir:
            i = turn(i, dir[cnt])
    
    return cnt
         
n = int(input())
k = int(input())

graph = [[0]*(n+1) for _ in range(n+1)]

for _ in range(k):
    x, y = map(int, input().split())
    graph[x][y] = 1

l = int(input())
dir = dict()
for _ in range(l):
    x, c = map(str, input().split())
    dir[int(x)] = c

# right, up, left, down
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

print(move())
