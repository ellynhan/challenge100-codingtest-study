import sys
sys.setrecursionlimit(20000)

input = sys.stdin.readline

def dfs(v, color):
    global error
    
    if error:
        return
    
    visited[v] = color
    
    for i in graph[v]:
        if visited[i] == False:
            dfs(i, -1 * color)
        elif visited[v] == visited[i]:
            error = True
            return


k = int(input())

for _ in range(k):
    v, e = map(int, input().split())
    
    graph = [[] for _ in range(v+1)]
    visited = [False] * (v+1)
    error = False
    
    for _ in range(e):
        a, b = map(int, input().split())
        
        graph[a].append(b)
        graph[b].append(a)
    
    
    for i in range(1, v+1):
        if visited[i] == False:
            dfs(i, 1)
            
            if error:
                break
    
    
    if error:
        print("NO")
    else:
        print("YES")