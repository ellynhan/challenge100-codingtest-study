r, c, t = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]
fresher = [(x, 0) for x in range(r) if a[x][0] == -1]


def dust():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    tmp = [[0]*c for _ in range(r)]
    for x in range(r):
        for y in range(c):
            if a[x][y] != -1:
                cnt = 0
                for d in zip(dx, dy):
                    nx, ny = x+d[0], y+d[1]
                    if 0 <= nx < r and 0 <= ny < c and a[nx][ny] != -1:
                        tmp[nx][ny] += a[x][y] // 5
                        cnt += 1
                tmp[x][y] -= a[x][y] // 5 * cnt
    for x in range(r):
        for y in range(c):
            a[x][y] += tmp[x][y]


def fresh():
    x, y = fresher[0]
    for tx, fx in zip(range(x-1, 0, -1), range(x-2, -1, -1)):
        a[tx][y] = a[fx][y]
    for ty, fy in zip(range(0, c-1), range(1, c)):
        a[0][ty] = a[0][fy]
    for tx, fx in zip(range(0, x), range(1, x+1)):
        a[tx][c-1] = a[fx][c-1]
    for ty, fy in zip(range(c-1, 1, -1), range(c-2, 0, -1)):
        a[x][ty] = a[x][fy]
    a[x][y+1] = 0

    x, y = fresher[1]
    for tx, fx in zip(range(x+1, r-1), range(x+2, r)):
        a[tx][y] = a[fx][y]
    for ty, fy in zip(range(0, c-1), range(1, c)):
        a[r-1][ty] = a[r-1][fy]
    for tx, fx in zip(range(r-1, x, -1), range(r-2, x-1, -1)):
        a[tx][c-1] = a[fx][c-1]
    for ty, fy in zip(range(c-1, 1, -1), range(c-2, 0, -1)):
        a[x][ty] = a[x][fy]
    a[x][y+1] = 0


for _ in range(t):
    dust()
    fresh()

answer = 0
for i in range(r):
    for j in range(c):
        if a[i][j] != -1:
            answer += a[i][j]
print(answer)
