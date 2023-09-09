from collections import deque
from itertools import combinations

n, m = map(int, input().split())
maps = [
    list(map(int, input().split()))
    for _ in range(n)
]

walls = []
# 벽의 위치 3군데 선정
for i in range(n):
    for j in range(m):
        if maps[i][j] == 0:
            walls.append((i, j))

selected_walls = list(combinations(walls, 3))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    global visited
    global new_maps

    queue = deque([(x, y)])
    visited[x][y] = True
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue

            if not visited[nx][ny] and new_maps[nx][ny] == 0:
                new_maps[nx][ny] = 2
                visited[nx][ny] = True
                queue.append((nx, ny))


# 선정한 위치 바이러스 탐색
max_count = 0
for a, b, c in selected_walls:
    new_maps = [row[:] for row in maps]
    new_maps[a[0]][a[1]] = 1
    new_maps[b[0]][b[1]] = 1
    new_maps[c[0]][c[1]] = 1

    visited = [[False for _ in range(m)] for _ in range(n)]
    for x in range(n):
        for y in range(m):
            if not visited[x][y] and new_maps[x][y] == 2:
                bfs(x, y)

    count = 0
    # 최대 안전영역 비교
    for i in range(n):
        for j in range(m):
            if new_maps[i][j] == 0:
                count += 1

    max_count = max(max_count, count)

print(max_count)
