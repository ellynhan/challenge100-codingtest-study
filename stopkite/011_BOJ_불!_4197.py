from collections import deque

answer = []

n, m = map(int, input().split())
maps = [input() for _ in range(n)]
dist1 = [[-1] * m for _ in range(n)]  # 불
dist2 = [[-1] * m for _ in range(n)]  # 지훈

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

queue1 = deque()  # 불
queue2 = deque()  # 지훈

for i in range(n):
    for j in range(m):
        if maps[i][j] == 'F':
            queue1.append((i, j))
            dist1[i][j] = 0
        elif maps[i][j] == 'J':
            queue2.append((i, j))
            dist2[i][j] = 0

# 불의 이동에 대한 bfs
while queue1:
    x, y = queue1.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if dist1[nx][ny] == -1 and maps[nx][ny] != '#':
            dist1[nx][ny] = dist1[x][y] + 1
            queue1.append((nx, ny))

# 지훈 이동에 대한 bfs
while queue2:
    x, y = queue2.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            answer.append(dist2[x][y] + 1)
            break
        if dist2[nx][ny] == -1 and maps[nx][ny] != '#':
            if dist1[nx][ny] == -1 or dist1[nx][ny] > dist2[x][y] + 1:
                dist2[nx][ny] = dist2[x][y] + 1
                queue2.append((nx, ny))

if not answer:
    print("IMPOSSIBLE")
else:
    print(min(answer))


