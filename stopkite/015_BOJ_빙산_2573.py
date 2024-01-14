import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
ice = [
    list(map(int, sys.stdin.readline().split()))
    for _ in range(n)
]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


# 한 개의 빙산 영역 탐색
def bfs(x, y, vs):
    vs[x][y] = True
    queue = deque([(x, y)])
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if not vs[nx][ny] and ice[nx][ny] > 0:
                vs[nx][ny] = True
                queue.append((nx, ny))


# 빙하 녹이기
def melt_ice():
    new_ice = [[0] * m for _ in range(n)]  # 새로운 빙하 상태를 저장할 배열
    for i in range(n):
        for j in range(m):
            if ice[i][j] > 0:
                melted = melt_ice_cell(i, j)
                new_ice[i][j] = max(ice[i][j] - melted, 0)
    return new_ice


# 빙하 한 칸 녹이기
def melt_ice_cell(x, y):
    melted = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if ice[nx][ny] == 0:
            melted += 1
    return melted


count = 0
time = 0
while True:
    visited = [[False] * m for _ in range(n)]
    count = 0

    # 한 개의 빙산 영역 탐색
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and ice[i][j] > 0:
                bfs(i, j, visited)
                count += 1

    if count >= 2:  # 빙산 개수 탐색
        print(time)
        break

    if count == 0:
        print(0)
        break

    # 얼음 녹이기
    ice = melt_ice()

    time += 1
