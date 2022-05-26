from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(i, j, maps, visit):
    q = deque()
    q.append((i, j))

    while q:
        x, y = q.popleft()

        if visit[x][y]:
            continue

        visit[x][y] = True

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if nx < 0 or nx >= len(maps) or ny < 0 or ny >= len(maps[0]):
                continue

            elif not visit[nx][ny] and maps[nx][ny] != 0:
                maps[nx][ny] = maps[x][y] + 1
                q.append((nx, ny))

def solution(maps):
    visit = [[False]*len(maps[0]) for _ in range(len(maps))]
    bfs(0, 0, maps, visit)
    return maps[-1][-1] if maps[-1][-1] != 1 else -1