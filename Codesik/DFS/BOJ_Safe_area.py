import copy
import sys


def dfs(min_h, graph, i, j, is_discovered=False):
    if i < 0 or i >= N or j < 0 or j >= N:
        return
    if graph[i][j] == 'S':
        return
    if graph[i][j] > min_h:
        is_discovered = True
        graph[i][j] = 'S'
        dfs(min_h, graph, i + 1, j, is_discovered)
        dfs(min_h, graph, i - 1, j, is_discovered)
        dfs(min_h, graph, i, j - 1, is_discovered)
        dfs(min_h, graph, i, j + 1, is_discovered)
    return is_discovered


N = int(input())
graph = []
max_h = 0
answer = -sys.maxsize
sys.setrecursionlimit(10**9)
for _ in range(N):
    arr = list(map(int, input().split()))
    for el in arr:
        max_h = max(max_h, el)
    graph.append(arr)

for h in range(max_h + 2):
    result = 0
    graph_result = copy.deepcopy(graph)
    # print("높이:",h)
    for i in range(N):
        for j in range(N):
            if graph_result[i][j] == 'S':
                continue
            is_discovered = dfs(h, graph_result, i, j, 0)
            if is_discovered:
                result += 1

    answer = max(answer, result)

print(answer)
