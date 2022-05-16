from collections import defaultdict, Counter
from heapq import heappop, heappush

def dijkstra(start, graph, n):
    q = []
    distance = [int(1e9)]*(n+1)
    distance[0] = 0
    heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, node = heappop(q)
        if distance[node] < dist:
            continue
        for next in graph[node]:
            cost = distance[node] + 1
            if cost < distance[next]:
                distance[next] = cost
                heappush(q, (cost, next))
    return distance

def solution(n, edge):
    graph = defaultdict(set)

    for e_from, e_to in edge:
        graph[e_from].add(e_to)
        graph[e_to].add(e_from)

    distance = dijkstra(1, graph, n)
    return sorted(Counter(distance).items(), key=lambda x:x[0], reverse=True)[0][1]