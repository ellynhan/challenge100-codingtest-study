import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [ [] for _ in range(N+1)]
visited = [False] * (N+1)

for i in range(M):
    V1, V2 = map(int, sys.stdin.readline().split())
    graph[V1].append(V2)
    graph[V2].append(V1)

for i in range(N+1):
    graph[i].sort()

def dfs(graph, v):
    global visited
    visited[v] = True

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i)

#print(graph)
dfs(graph, 1)

cnt = 0
for v in visited:
    if v:
        cnt += 1

#print(visited)
print(cnt - 1)
