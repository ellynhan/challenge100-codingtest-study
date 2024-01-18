from collections import deque

m, n = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

queue = deque([])
for x in range(n):
    for y in range(m):
        if maps[x][y] == 1:
            queue.append((x, y))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while queue:
    x, y = queue.popleft()
    visited[x][y] = True
    for i in range(4):
        nx = dx[i] + x
        ny = dy[i] + y
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if not visited[nx][ny] and maps[nx][ny] == 0:
            visited[nx][ny] = True
            maps[nx][ny] = maps[x][y] + 1
            queue.append((nx, ny))

flag = True
answer = 0
for i in range(n):
    for j in range(m):
        if maps[i][j] == 0:
            flag = False
            break
        else:
            answer = max(answer, maps[i][j])

if flag:
    print(answer - 1)
else:
    print(-1)
