import sys
import heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

INF = int(1e9)
distance = [INF] * (n + 1)

visited = [0] * (n + 1)
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    st, ed, cost = map(int, sys.stdin.readline().split())
    graph[st].append((cost, ed))

start, end = map(int, sys.stdin.readline().split())

pq = []
heapq.heappush(pq, (0, start))
distance[start] = 0
while pq:
    cur_dist, cur_v = heapq.heappop(pq)
    if distance[cur_v] < cur_dist:
        continue
    for dist, next_v in graph[cur_v]:
        next_dist = dist + cur_dist
        if next_dist >= distance[next_v]:
            continue
        distance[next_v] = next_dist
        visited[next_v] = cur_v
        heapq.heappush(pq, (next_dist, next_v))


print(distance[end])

path = [end]
current = end
while start != current:
    path.append(visited[current])
    current = visited[current]


print(len(path))
print(*path[::-1])
