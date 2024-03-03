import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
sys.setrecursionlimit(10**6)

def findConnected(node):

    for i in graph[node]:
        if not visited[i]:
            visited[i] = 1
            findConnected(i)


N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

cnt = 1
for i in range(1,N+1):
    if not visited[i]:
        findConnected(i)
        cnt += 1

print(cnt-1)
