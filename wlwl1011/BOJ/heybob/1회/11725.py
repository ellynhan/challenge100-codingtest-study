import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
tree = [[] for _ in range(N+1)]
parent = [0] * (N+1)

for _ in range(N-1):
    node1, node2 = map(int, input().split())
    tree[node1].append(node2)
    tree[node2].append(node2)
     
def dfs(s):
    for i in tree[s]:
        if parent[i] == 0:
            visited[i] = s
            dfs(i)
    
dfs(1)

for x in range(2, N+1):
    print(parent[x])            