n = int(input())
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

a = [[0] * 101 for _ in range(101)]
for _ in range(n):
    x, y, d, g = map(int, input().split())

    seq = [d]
    for _ in range(g):
        seq += list((mv + 1) % 4 for mv in seq[::-1])
    
    a[x][y] = 1
    for mv in seq:
        nx, ny = x + dx[mv], y + dy[mv]
        a[nx][ny] = 1
        x, y = nx, ny
    
answer = 0
for i in range(100):
    for j in range(100):
        if a[i][j] and a[i+1][j] and a[i][j+1] and a[i+1][j+1]:
            answer += 1
print(answer)
