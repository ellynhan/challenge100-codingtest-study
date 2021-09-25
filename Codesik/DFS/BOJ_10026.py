import copy

#10:20
import sys


def dfs(i, j, graph, start=True, color=None, is_found=False):
    if i >= N or i < 0 or j >= N or j < 0:
        return
    if start and graph[i][j] != 'V':
        is_found = True
        color = graph[i][j]
        graph[i][j] = 'V'
        for e in range(4):
            dfs(i+dy[e], j+dx[e], graph, False, color)
    elif graph[i][j] != 'V' and color == graph[i][j]:
        graph[i][j] = 'V'
        for e in range(4):
            dfs(i+dy[e], j+dx[e], graph, False, color)
    return is_found


sys.setrecursionlimit(10**9)
N = int(input())
RGB_graph = []
for _ in range(N):
    arr = list(input())
    RGB_graph.append(arr)

RB_graph = copy.deepcopy(RGB_graph)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

RGB = 0
RB = 0
for i in range(N):
    for j in range(N):
        if RB_graph[i][j] == 'G':
            RB_graph[i][j] = 'R'

for i in range(N):
    for j in range(N):
        if dfs(i, j, RGB_graph):
            RGB += 1
        if dfs(i, j, RB_graph):
            RB += 1
print(f'{RGB} {RB}')
