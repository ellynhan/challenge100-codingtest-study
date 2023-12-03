import heapq
import sys

n, m, k, x = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append((1, b))

costs = {}
dq = []
heapq.heappush(dq, (0, x))

while dq:
    cur_cost, cur_v = heapq.heappop(dq)
    if cur_v not in costs:
        costs[cur_v] = cur_cost
        for cost, next_v in graph[cur_v]:
            next_cost = cur_cost + cost
            heapq.heappush(dq, (next_cost, next_v))

for key, value in costs.items():
    if value == k:
        print(key)

if k not in costs.values():
    print(-1)
