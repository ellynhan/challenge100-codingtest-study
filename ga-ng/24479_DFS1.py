import sys
sys.setrecursionlimit(10**9)

def dfs(r):
    global cnt
    
    visited[r] = cnt
    cnt += 1
    
    graph[r].sort()
    
    for i in graph[r]:
        if visited[i] == 0:
            dfs(i)

input = sys.stdin.readline

n, m, r = map(int, input().split())

graph = [[]for _ in range(n+1)]
visited = [0]*(n+1)
cnt = 1

for _ in range(m):
    a,b = map(int, input().split())
    
    graph[a].append(b)
    graph[b].append(a)

dfs(r)

for i in visited[1:]:
    print(i)