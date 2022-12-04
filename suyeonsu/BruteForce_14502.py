from itertools import combinations

def dfs(x, y):
    for dx, dy in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
            board[nx][ny] = 2
            dfs(nx, ny)

n, m = map(int, input().split())
_board = [list(map(int, input().split())) for _ in range(n)]
idx = [(i, j) for i in range(n) for j in range(m) if _board[i][j] == 0]

answer = 0
for w1, w2, w3 in combinations(idx, 3):
    board = list(_board[i].copy() for i in range(n))
    board[w1[0]][w1[1]] = 1
    board[w2[0]][w2[1]] = 1
    board[w3[0]][w3[1]] = 1

    safezone = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 2:
                dfs(i, j)
    for i in range(n):
        safezone += board[i].count(0)
    answer = max(answer, safezone)

print(answer)
