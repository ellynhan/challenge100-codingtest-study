import sys
import heapq

v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

graph = [[] for _ in range(v + 1)]
for _ in range(e):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((w, v))

pq = []
costs = {}
heapq.heappush(pq, (0, k))
while pq:
    cur_cost, cur_v = heapq.heappop(pq)
    if cur_v not in costs:
        costs[cur_v] = cur_cost
        for cost, next_v in graph[cur_v]:
            new_cost = cur_cost + cost
            heapq.heappush(pq, (new_cost, next_v))

for i in range(1, len(graph)):
    if i not in costs:
        print("INF")
    else:
        print(costs[i])
