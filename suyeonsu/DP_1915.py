n, m = map(int, input().split())
board = [list(map(int, list(input()))) for _ in range(n)]
answer = 0
for i in range(1, n):
    for j in range(1, m):
        if board[i][j]:
            board[i][j] += min(board[i-1][j], board[i][j-1], board[i-1][j-1])
for row in board:
    answer = max(answer, max(row))
print(answer**2)
