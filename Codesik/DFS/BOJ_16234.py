# https://www.acmicpc.net/problem/16234
import sys
sys.setrecursionlimit(10**5)
def dfs(i, j, temp, visit):
    visit[i][j] = 1
    for d in range(4):
        nx = dx[d] + i
        ny = dy[d] + j
        if 0 <= nx < N and 0 <= ny < N and not visit[nx][ny]:
            if L <= abs(graph[i][j] - graph[nx][ny]) <= R:
                temp.append((nx, ny))
                dfs(nx, ny, temp, visit)
    return temp


N, L, R = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
cnt = 0

while True:
    is_changed = False
    visit = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            temp = [(i, j)]
            if not visit[i][j]:
                temp = dfs(i, j, temp, visit)
                if len(temp) > 1:
                    is_changed = True
                    sum_of_people = 0
                    for c, d in temp:
                        sum_of_people += graph[c][d]
                    result_of_people = sum_of_people // len(temp)
                    for a, b in temp:
                        graph[a][b] = result_of_people
    if not is_changed:
        break
    cnt += 1
print(cnt)