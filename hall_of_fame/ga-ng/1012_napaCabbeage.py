import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def dfs(x,y):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    
    if graph[x][y] == 1:
        graph[x][y] = 0
        
        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x, y-1)
        
        return True
    
    return False

t = int(input())


for _ in range(t):
    
    m, n, k = map(int, input().split())
    
    graph = [[0]*m for _ in range(n)]
    
    for _ in range(k):
        a, b = map(int, input().split())
        graph[b][a] = 1
        
    res = 0
    for i in range(n):
        for j in range(m):
            if dfs(i,j) == True:
                res += 1
                
    print(res)