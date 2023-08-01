import sys
from collections import deque

N = int(sys.stdin.readline())
graph = []
for i in range(N):
    graph.append(list(sys.stdin.readline()[:-1]))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

cnt = 0
def dfs(x, y):
    global cnt
    if x < 0 or x >= N or y < 0 or y >= N:
        return False

    if graph[x][y] == '1':
        cnt += 1
        graph[x][y] = '0'

        for i in range(4):
            dfs(x + dx[i], y + dy[i])

        return True
    
    return False

result_l = []


for i in range(N):
    for j in range(N):
        if dfs(i, j) == True:
            result_l.append(cnt)
            cnt = 0

result_l.sort()
print(len(result_l), *result_l, sep="\n")
