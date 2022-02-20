import sys


def dfs(i, j, graph, is_island=False):
    if i >= h or i < 0 or j >= w or j < 0:
        return
    if graph[i][j] == 1:
        graph[i][j] = 2
        is_island = True
        dfs(i + 1, j, graph, is_island)
        dfs(i - 1, j, graph, is_island)
        dfs(i, j + 1, graph, is_island)
        dfs(i, j - 1, graph, is_island)
        dfs(i + 1, j + 1, graph, is_island)
        dfs(i - 1, j - 1, graph, is_island)
        dfs(i + 1, j - 1, graph, is_island)
        dfs(i - 1, j + 1, graph, is_island)

    return is_island

sys.setrecursionlimit(10**9)
# 5, 4
while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break
    graph = []
    answer = 0
    for _ in range(h):
        arr = list(map(int, input().split()))
        graph.append(arr)

    for i in range(h):
        for j in range(w):
            if graph[i][j] == 1:
                if dfs(i, j, graph):
                    answer += 1
    print(answer)


