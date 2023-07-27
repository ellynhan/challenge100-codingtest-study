import sys
from collections import deque

N, M, V = map(int, sys.stdin.readline().split())
graph = [ [] for _ in range(N+1)]
visited = [False] * (N+1)

for i in range(M):
    V1, V2 = map(int, sys.stdin.readline().split())
    graph[V1].append(V2)
    graph[V2].append(V1)

for i in range(N+1):
    graph[i].sort()


def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=" ")

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    visited[start] = True
    q = deque([start])

    while q:
        v = q.popleft()
        print(v, end=" ")

        for i in graph[v]:
            if not visited[i]:
                q.append(i)
                visited[i] = True


#print(graph)
dfs(graph, V, visited)
print()
visited = [False] * (N+1)
bfs(graph, V, visited)
