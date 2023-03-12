from collections import deque

nxtState = {1: {(-1, 0): [1, 2, 5, 6],  (1, 0): [1, 2, 4, 7], (0, -1): [1, 3, 4, 5], (0, 1): [1, 3, 6, 7]},
           2: {(-1, 0): [1, 2, 5, 6], (1, 0): [1, 2, 4, 7]},
           3: {(0, -1): [1, 3, 4, 5], (0, 1): [1, 3, 6, 7]},
           4: {(-1, 0): [1, 2, 5, 6], (0, 1): [1, 3, 6, 7]},
           5: {(1, 0): [1, 2, 4, 7], (0, 1): [1, 3, 6, 7]},
           6: {(1, 0): [1, 2, 4, 7], (0, -1): [1, 3, 4, 5]},
           7: {(-1, 0): [1, 2, 5, 6], (0, -1): [1, 3, 4, 5]}}

T = int(input())
for t in range(1, T+1):
    n, m, r, c, l = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(n)]
    visited = [[0] * m for _ in range(n)]

    dq = deque([(1, r, c, board[r][c])])
    visited[r][c] = 1
    answer = set([(r, c)])
    while dq:
        lev, x, y, state = dq.popleft()
        if lev == l: break
        for (dx, dy), lst in nxtState[state].items():
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] in lst and not visited[nx][ny]:
                dq.append((lev+1, nx, ny, board[nx][ny]))
                visited[nx][ny] = 1
                answer.add((nx, ny))
    print(f'#{t} {len(answer)}')
