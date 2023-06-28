from heapq import heappop, heappush

tc = 1
while True:
    n = int(input())
    if n == 0: break
    board = [list(map(int, input().split())) for _ in range(n)]
    cost = [[1e9]*n for _ in range(n)]
    visited = [[0]*n for _ in range(n)]

    hq = [(board[0][0], 0, 0)]
    cost[0][0] = board[0][0]
    while hq:
        c, x, y = heappop(hq)
        visited[x][y] = 1
        if c > cost[x][y]: continue
        for dx, dy in (-1, 0), (0, -1), (1, 0), (0, 1):
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and board[nx][ny]+c < cost[nx][ny]:
                heappush(hq, (board[nx][ny]+c, nx, ny))
                cost[nx][ny] = board[nx][ny]+c
    print(f'Problem {tc}: {cost[n-1][n-1]}')
    tc += 1
