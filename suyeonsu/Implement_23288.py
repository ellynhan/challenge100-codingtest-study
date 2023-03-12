from collections import deque

answer = 0
n, m, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

up, down, east, west, south, north = 1, 6, 3, 4, 5, 2
x, y = 0, 0
dir = 0
dx = [0, 0, 1, -1]  # 동, 서, 남, 북
dy = [1, -1, 0, 0]


def move_dice():
    global x, y, dir, up, down, east, west, south, north
    nx, ny = x + dx[dir], y + dy[dir]
    if nx < 0 or nx >= n or ny < 0 or ny >= m:
        if dir == 1:
            dir = 0
        elif dir == 0:
            dir = 1
        elif dir == 2:
            dir = 3
        else:
            dir = 2
    x += dx[dir]
    y += dy[dir]
    if dir == 0:
        east, down, west, up = up, east, down, west
    elif dir == 1:
        west, down, east, up = up, west, down, east
    elif dir == 2:
        south, down, north, up = up, south, down, north
    else:
        north, down, south, up = up, north, down, south


def calc_score(b):
    global answer
    visited = [[0] * m for _ in range(n)]
    dq = deque([(x, y)])
    visited[x][y] = 1
    cnt = 1
    while dq:
        cur = dq.popleft()
        for d in zip(dx, dy):
            nx, ny = cur[0]+d[0], cur[1]+d[1]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and board[nx][ny] == b:
                dq.append((nx, ny))
                visited[nx][ny] = 1
                cnt += 1
    answer += cnt*b


def set_direction(a, b):
    global dir
    if a > b:
        dir = dir+2 if dir+2 <= 3 else 3-dir
    elif a < b:
        dir = dir-2 if dir-2 >= 0 else abs(dir-3)


for _ in range(k):
    move_dice()
    calc_score(board[x][y])
    set_direction(down, board[x][y])
print(answer)
