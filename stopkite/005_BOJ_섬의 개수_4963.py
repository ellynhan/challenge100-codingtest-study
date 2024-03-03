from collections import deque

dx = [-1, 1, 0, 0, -1, 1, -1, 1]
dy = [0, 0, -1, 1, 1, -1, -1, 1]

while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break

    maps = [list(map(int, input().split())) for _ in range(h)]
    visited = [[False] * w for _ in range(h)]

    def bfs(x, y):
        queue = deque([(x, y)])
        visited[x][y] = True
        while queue:
            x, y = queue.popleft()
            for i in range(8):
                nx = dx[i] + x
                ny = dy[i] + y

                if nx < 0 or nx >= h or ny < 0 or ny >= w:
                    continue
                if not visited[nx][ny] and maps[nx][ny] == 1:
                    visited[nx][ny] = True
                    queue.append((nx, ny))

    count = 0
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and maps[i][j] == 1:
                bfs(i, j)
                count += 1

    print(count)
