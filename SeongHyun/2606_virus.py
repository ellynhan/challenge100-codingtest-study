import sys

def dfs(G, v, discovered=[]):
    discovered.append(v)
    for w in G[v]:
        if w not in discovered:
            dfs(G, w)
    return discovered
    

computer_num = int(input())
edge_num = int(input())
graph = {i+1:set() for i in range(computer_num)}

for _ in range(edge_num): #graph구성
    edge = list(map(int,sys.stdin.readline().split()))
    graph[edge[0]].add(edge[1])
    graph[edge[1]].add(edge[0])

print(len(dfs(graph, 1))-1)
