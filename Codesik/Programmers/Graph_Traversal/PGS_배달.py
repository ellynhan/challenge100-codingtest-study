from collections import defaultdict
from heapq import heappush, heappop

def solution(N, road, K):
    answer = 0

    graph = defaultdict(list)
    for v_from, v_to, cost in road:
        graph[v_from].append((v_to, cost))
        graph[v_to].append((v_from, cost))

    distance = {key: int(1e9) for key in graph.keys()}
    distance[1] = 0

    queue = []
    heappush(queue, (distance[1], 1))

    while queue:
        current_distance, current_node = heappop(queue)
        if current_distance > distance[current_node]:
            continue

        for new_node, new_cost in graph[current_node]:
            d = current_distance + new_cost

            if d < distance[new_node]:
                distance[new_node] = d
                heappush(queue, (d, new_node))

    for d in distance.values():
        answer = answer + 1 if d <= K else answer

    return answer