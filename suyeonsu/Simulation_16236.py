from heapq import heappush, heappop
from collections import deque

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
baby = 0, 0
for i in range(n):
    for j in range(n):
        if board[i][j] == 9:
            baby = i, j
size = 2
cnt = 0

time = 0
while True:
    fish = []
    visited = [[0] * n for _ in range(n)]
    dq = deque([(baby[0], baby[1], 0)])
    visited[baby[0]][baby[1]] = 1
    min_cost = 1e9
    while dq:
        x, y, cost = dq.popleft()
        if 1 <= board[x][y] < size:
            if cost <= min_cost:
                heappush(fish, (cost, x, y))
                min_cost = cost
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and board[nx][ny] <= size:
                dq.append((nx, ny, cost+1))
                visited[nx][ny] = 1
    if fish:
        cost, x, y = heappop(fish)
        time += cost
        board[baby[0]][baby[1]] = 0
        baby = x, y
        board[x][y] = 9
        cnt += 1
        if cnt == size:
            size += 1
            if size > 9: size = 9
            cnt = 0
    else:
        break
print(time)
