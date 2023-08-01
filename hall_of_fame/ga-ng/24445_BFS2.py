import sys
from collections import deque
input = sys.stdin.readline

def bfs(r):
    global cnt
    
    q = deque()
    q.append(r)
    visited[r] = cnt
    cnt += 1
    
    while q:
        r = q.popleft()
        
        graph[r].sort(reverse=True)
        
        for i in graph[r]:
            if visited[i] == 0:
                visited[i] = cnt
                cnt += 1
                q.append(i)


n, m, r = map(int, input().split())

graph = [[] for _ in range(n+1)]
visited = [0 for _ in range(n+1)]
cnt = 1

for i in range(m):
    a, b = map(int, input().split())
    
    graph[a].append(b)
    graph[b].append(a)
    

bfs(r)

for i in range(1, n+1):
    print(visited[i])