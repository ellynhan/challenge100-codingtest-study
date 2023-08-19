n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
answer = 1
for x in range(n):
    for y in range(m):
        for k in range(max(n, m)+1):
            if x+k < n and y+k < m:
                if board[x][y] == board[x+k][y] == board[x][y+k] == board[x+k][y+k]:
                    answer = max(answer, (k+1)**2)
print(answer)
