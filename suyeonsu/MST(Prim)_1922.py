import heapq
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = {i:[] for i in range(1, n+1)}
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

cost = 0
hq = [(0, 1)]
visited = []
while len(visited) < n:
    c, i = heapq.heappop(hq)
    if i not in visited:
        visited.append(i)
        cost += c
        for edge in graph[i]:
            heapq.heappush(hq, edge)
print(cost)
