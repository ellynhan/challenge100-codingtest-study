n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

def dfs(x, y):
    nx = x+1
    if nx < n and board[nx][y] == '|' and not visited[nx][y]:
        visited[nx][y] = 1
        dfs(nx, y)

answer = 0
for row in board:
    answer += len([e for e in (''.join(row)).split('|') if e])
for i in range(n):
    for j in range(m):
        if board[i][j] == '|' and not visited[i][j]:
            answer += 1
            visited[i][j] = 1
            dfs(i, j)
print(answer)
