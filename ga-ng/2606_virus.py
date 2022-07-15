import sys

input = sys.stdin.readline

def dfs(r):
    global cnt
    visited[r] = 1
    
    for i in graph[r]:
        if visited[i] == 0:
            cnt += 1
            dfs(i)
    

cptNum = int(input())
nodeNum = int(input())

graph = [[] for _ in range(cptNum+1)]
visited = [0 for _ in range(cptNum+1)]
cnt = 1

for i in range(nodeNum):
    a, b = map(int, input().split())
    
    graph[a].append(b)
    graph[b].append(a)
    
dfs(1)

print(cnt)