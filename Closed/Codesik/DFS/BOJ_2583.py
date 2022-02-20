# 9:26
import sys


def dfs(i, j, graph):
    global cnt
    if i >= M or i < 0 or j >= N or j < 0:
        return
    if graph[i][j] == 0:
        graph[i][j] = 1
        cnt += 1
        for e in range(4):
            ny = i+dy[e]
            nx = j+dx[e]
            dfs(ny, nx, graph)

sys.setrecursionlimit(10**9)
answer = []
cnt = 0
M, N, K = map(int, input().split())
graph = [[0]*(N) for _ in range(M)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(K):
    # a2, a4가 y좌표, 즉 M
    # a1, a3가 x좌표, 즉 N
    a1, a2, a3, a4 = map(int, input().split())
    for y in range(a2, a4):
        graph[y][a1:a3] = [1]*(a3-a1)

for i in range(M):
    for j in range(N):
        if graph[i][j] == 1:
            continue
        dfs(i, j, graph)
        answer.append(cnt)
        cnt = 0

print(len(answer))
for ans in sorted(answer):
    print(ans, end = ' ')