# 다익스트라는 get_min_node 빼오는 게 핵심
from collections import defaultdict
# import heapq
def get_min_node():
    m = INF +1
    idx = -1
    for i in range(V+1):
        if not visit[i] and m > distance[i]:
            m = distance[i]
            idx = i
    return idx

def dijkstra(x):
    visit[0] = True
    distance[K] = 0

    while False in visit:
        now = get_min_node()
        visit[now] = True
        for v, w in path[now]:
            if (not visit[v]) and (distance[now]+w < distance[v]):
                distance[v] = distance[now]+w

INF = 10000000

V, E = map(int, input().split(" "))
K = int(input())
path = defaultdict(list)
distance = [INF]*(V+1)
visit = [False] * (V+1)
for _ in range(E):
    u, v, w = map(int, input().split(" "))
    path[u].append((v,w))

dijkstra(K)
# print(answer)

for i in range(1, V+1):
    if distance[i] == INF:
        print('INF')
    else:
        print(distance[i])

