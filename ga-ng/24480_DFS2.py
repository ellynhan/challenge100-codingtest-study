import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

n, m, r = map(int, input().split())

graph = [[] for _ in range(n+1)]
visited = [0 for _ in range(n+1)]
cnt = 1

for i in range(m):
    a, b = map(int, input().split())
    
    graph[a].append(b)
    graph[b].append(a)
    
def dfs(r):
    global cnt
    
    visited[r] = cnt
    cnt += 1
    
    graph[r].sort(reverse=True)

    
    for next in graph[r]:
        if visited[next] == 0:
            dfs(next)   


dfs(r)

for cnt in range(1, n+1):
    print(visited[cnt])