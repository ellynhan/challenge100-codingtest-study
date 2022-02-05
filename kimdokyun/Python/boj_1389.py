graph = [[9999] * 101 for i in range(101)]

N,M = map(int, input().split())
for i in range(M):
    a,b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1
for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

print( min( [ (sum(graph[i]), i) for i in range(1, N+1) ] )[1] )