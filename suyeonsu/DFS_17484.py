n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 1e9
dy = [-1, 0, 1]
dest = 0

def dfs(x, y, cost, d):
    global answer
    if cost >= answer: return
    if (x, y) == dest:
        answer = min(answer, cost)
        return
    for i in range(3):
        nx, ny = x+1, y+dy[i]
        if d != i and 0 <= nx < n and 0 <= ny < m:
            dfs(nx, ny, cost + board[nx][ny], i)

for sx, sy in zip([0]*m, range(m)):
    for ex, ey in zip([n-1]*m, range(m)):
        dest = ex, ey
        dfs(sx, sy, board[sx][sy], -1)
print(answer)
