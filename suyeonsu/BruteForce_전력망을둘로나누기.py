# DFS
visited = []
adj = []

def dfs(v, adj):
    global visited
    for nxt in range(len(adj[v])):
        if adj[v][nxt] and not visited[nxt]:
            visited[nxt] = 1
            dfs(nxt, adj)

def solution(n, wires):
    global visited
    adj = [[0] * n for _ in range(n)]
    for v1, v2 in wires:
        adj[v1-1][v2-1] = 1
        adj[v2-1][v1-1] = 1
        
    answer = n
    for v1, v2 in wires:
        visited = [0] * n
        adj[v1-1][v2-1] = 0
        adj[v2-1][v1-1] = 0
        
        visited[0] = 1
        dfs(0, adj)
        answer = min(abs(visited.count(0) - visited.count(1)), answer)
        
        adj[v1-1][v2-1] = 1
        adj[v2-1][v1-1] = 1
    return answer

# BFS (n이 작았기 때문에 실행시간에서 큰 차이는 없었다.)
from collections import deque

def solution(n, wires):
    adj = [[0] * n for _ in range(n)]
    for v1, v2 in wires:
        adj[v1-1][v2-1] = 1
        adj[v2-1][v1-1] = 1
        
    answer = n
    for v1, v2 in wires:
        visited = [0] * n
        adj[v1-1][v2-1] = 0
        adj[v2-1][v1-1] = 0
        
        visited[0] = 1
        dq = deque([0])
        while dq:
            i = dq.popleft()
            for nxt in range(n):
                if adj[i][nxt] and not visited[nxt]:
                    visited[nxt] = 1
                    dq.append(nxt)
        answer = min(abs(visited.count(0) - visited.count(1)), answer)
        
        adj[v1-1][v2-1] = 1
        adj[v2-1][v1-1] = 1
    return answer

# UnionFind를 사용한 경우도 있었는데 실행시간이 매우 빨랐다.
