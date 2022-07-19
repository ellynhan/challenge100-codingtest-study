from collections import deque

def dfs(v):
    
    visited1[v] = 1 ## 방문처리
    
    print(v, end = " ")
    
    for i in range(1, n+1):
        if (visited1[i] == 0 and graph[v][i] == 1):
            dfs(i)
            
def bfs(v):
    que = deque()
    
    que.append(v)
    visited2[v] = 1
    
    while que:
        vertex = que.popleft()
        print(vertex, end = " ")
        
        for i in range(1, n+1):
            if (visited2[i] == 0 and graph[vertex][i] == 1):
                que.append(i)
                visited2[i] = 1
        
    
            



n, m, v = map(int, input().split())

graph = [[0] * (n+1) for _ in range(n+1)]

visited1 = [0] * (n+1)
visited2 = [0] * (n+1)

for _ in range(m):
    x, y = map(int, input().split())
    
    graph[x][y] = graph[y][x] = 1
    
    
dfs(v)
print()
bfs(v)