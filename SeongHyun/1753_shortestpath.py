import heapq
import collections
import sys
input = sys.stdin.readline

vertex, edge = map(int, input().split())
start = int(input())
graph = collections.defaultdict(list)

for _ in range(edge):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

Q = [(0, start)]
dist = collections.defaultdict(int)

while Q:
    time, node = heapq.heappop(Q)
    if node not in dist:
        dist[node] = time
        for v, w in graph[node]:
            alt = time + w
            heapq.heappush(Q, (alt, v))

for i in range(1, vertex+1):
    if i not in dist:
        print("INF")
        continue
    print(dist[i])
