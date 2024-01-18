import copy
from collections import deque

n = int(input())
grid1 = [list(input()) for _ in range(n)]
visited = [[False] * n for _ in range(n)]

grid2 = copy.deepcopy(grid1)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y, color, grid):
    queue = deque([(x, y)])
    visited[x][y] = True
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if not visited[nx][ny] and grid[nx][ny] == color:
                visited[nx][ny] = True
                queue.append((nx, ny))


count1 = 0
for i in range(n):
    for j in range(n):
        if grid1[i][j] == "R":
            grid2[i][j] = "G"
        if not visited[i][j]:
            bfs(i, j, grid1[i][j], grid1)
            count1 += 1

visited = [[False] * n for _ in range(n)]

count2 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j, grid2[i][j], grid2)
            count2 += 1

print(count1, count2)