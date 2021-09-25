from collections import *


def dfs(s, is_connected=False):
    for w in graph[s]:
        if not visited[w]:
            visited[w] = 1
            is_connected = True
            dfs(w, is_connected=is_connected)
    return is_connected


N, M = map(int, input().split())

graph = defaultdict(list)
visited = [0 for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)

answer = 0

for s in list(graph.keys()):
    if visited[s]:
        continue
    visited[s] = 1
    if dfs(s):
        answer += 1
for index, visited in enumerate(visited):
    if index == 0:
        continue
    if not visited:
        answer += 1
print(answer)
