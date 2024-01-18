"""
3차원 배열이 나올 꺼라 생각을 못해서 2차원으로 생각하다 막힘.
그리고 3차원 출력 시에도 z, x ,y 의 입출력이 헷갈려서 틀렸다!
"""
from collections import deque

m, n, h = map(int, input().split())  # 가로, 세로, 개수
box = [
    [list(map(int, input().split())) for _ in range(n)]
    for _ in range(h)
]

visited = [
    [[False] * m for _ in range(n)]
    for _ in range(h)
]


dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

queue = deque([])
for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                queue.append((i, j, k))

while queue:
    z, x, y = queue.popleft()
    visited[z][x][y] = True
    for i in range(6):
        nx = dx[i] + x
        ny = dy[i] + y
        nz = dz[i] + z
        if nx < 0 or nx >= n or ny < 0 or ny >= m or nz < 0 or nz >= h:
            continue
        if not visited[nz][nx][ny] and box[nz][nx][ny] == 0:
            visited[nz][nx][ny] = True
            box[nz][nx][ny] = box[z][x][y] + 1
            queue.append((nz, nx, ny))

flag = True
answer = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 0:
                flag = False
                break
            else:
                answer = max(answer, box[i][j][k])

if flag:
    print(answer - 1)
else:
    print(-1)


