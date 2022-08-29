import heapq

n, m = map(int, input().split())
sex = {i+1:s for i, s in enumerate(input().split())}
graph = {i:[] for i in range(1, n+1)}
for _ in range(m):
    a, b, c = map(int, input().split())
    if sex[a] != sex[b]:
        graph[a].append((c, b))
        graph[b].append((c, a))

cost = 0
hq = [(0, 1)]
visited = []
while len(visited) < n:
    if len(hq) == 0:
        cost = -1
        break
    c, i = heapq.heappop(hq)
    if i not in visited:
        visited.append(i)
        cost += c
        for edge in graph[i]:
            heapq.heappush(hq, edge)
print(cost)
