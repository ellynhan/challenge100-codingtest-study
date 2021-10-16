# 백준 1753번 최단경로
# 골드 5
import heapq

def dijkstra(graph, start):
    distances = {node : 11 for node in graph}
    distances[start] = 0
    queue = []
    heapq.heappush(queue, [distances[start], start])

    while queue:
        step_d, step_node = heapq.heappop(queue)
        if step_d > distances[step_node]:
            continue
        else:
            for destnode, destd in graph[step_node].items():
                dist = destd + step_d
                if dist < distances[destnode]:
                    distances[destnode] = dist
                    heapq.heappush(queue, [dist, destnode])
    return distances

V, E = map(int, input().split())
s = int(input()) -1

graph = {node : {} for node in range(V)}

for _ in range(E):
    u, v, w = map(int, input().split())
    if u-1 in graph.keys():
        graph[u-1][v-1] = w
    else:
        graph[u-1] = {v-1 : w}

d = dijkstra(graph, s)
for k in d.keys():
    i = d[k]
    if i == 11:
        print("INF")
    else:
        print(i)
