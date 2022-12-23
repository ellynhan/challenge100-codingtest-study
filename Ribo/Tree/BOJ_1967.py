import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def dfs(here, dist):
    global maxDist, maxNode
    if visited[here]: return 
    
    if maxDist < dist:
        maxDist = dist
        maxNode = here
        
    visited[here] = True
    
    for there, weight in tree[here]:
        nextDist = dist + weight
        dfs(there, nextDist)
    

    
n = int(input())
tree = [[] for _ in range(n+1)]

for _ in range(n-1):
    u, v, w = map(int, input().split())
    tree[u].append((v, w))
    tree[v].append((u, w))

maxDist = 0
maxNode = 0
visited = [False]*(n+1)
dfs(1, 0)

maxDist = 0
visited = [False]*(n+1)
dfs(maxNode, 0)

print(maxDist)
