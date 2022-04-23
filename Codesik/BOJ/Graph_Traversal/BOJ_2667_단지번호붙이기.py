def dfs(i, j):
    if graph[i][j] == '0':
        return

    global cnt
    cnt += 1
    graph[i][j] = '0'

    for a in range(4):
        ni = i + di[a]
        nj = j + dj[a]

        if 0 <= ni < N and 0 <= nj < N:
            dfs(ni, nj)

    return cnt


di = [1, -1, 0, 0]
dj = [0, 0, -1, 1]

N = int(input())

graph = []

for _ in range(N):
    graph.append(list(input()))

answer = []

for i in range(N):
    for j in range(N):
        if graph[i][j] == '1':
            global cnt
            cnt = 0
            dfs(i, j)
            answer.append(cnt)
        else:
            continue

print(len(answer))
for i in sorted(answer):
    print(i)