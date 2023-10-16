dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

def dfs(r, c, chance):
    global MAX, visited
    MAX = max(MAX, visited[r][c])
    for d in range(4):
        nr = r + dr[d]
        nc = c + dc[d]
        if not (0 <= nr < N and 0 <= nc < N) or visited[nr][nc]:
            continue
        if A[r][c] > A[nr][nc]:
            visited[nr][nc] = visited[r][c] + 1
            dfs(nr, nc, chance)
            visited[nr][nc] = 0
        elif chance and A[nr][nc] - K < A[r][c]:
            temp = A[nr][nc]
            A[nr][nc] = A[r][c] - 1
            visited[nr][nc] = visited[r][c] + 1
            dfs(nr, nc, chance-1)
            visited[nr][nc] = 0
            A[nr][nc] = temp

# main
T = int(input())
for tc in range(T):
    N, K = map(int, input().split())
    A = []
    top = 0
    for i in range(N):
        A.append(list(map(int, input().split())))
        for j in range(N):
            if A[i][j] > top:
                top = A[i][j]
    MAX = 0
    visited = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if A[i][j] == top:
                visited[i][j] = 1
                dfs(i, j, 1)
                visited[i][j] = 0

    print("#{} {}".format(tc+1, MAX))