n, m, x, y, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
l, r, f, b, u, d = 0, 0, 0, 0, 0, 0

dx = [0, (0, 1), (0, -1), (-1, 0), (1, 0)]
for i in list(map(int, input().split())):
    nx, ny = x+dx[i][0], y+dx[i][1]
    if 0 <= nx < n and 0 <= ny < m:
        x, y = nx, ny
        if i == 1:
            l, r, u, d = d, u, l, r
        elif i == 2:
            l, r, u, d = u, d, r, l
        elif i == 3:
            f, b, u, d = d, u, f, b
        else:
            f, b, u, d = u, d, b, f
        if board[x][y] == 0:
            board[x][y] = d
        else:
            d = board[x][y]
            board[x][y] = 0
        print(u)
