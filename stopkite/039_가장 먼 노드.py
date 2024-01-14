import heapq


def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    for i in range(len(edge)):
        a, b = edge[i][0], edge[i][1]
        graph[a].append((1, b))
        graph[b].append((1, a))

    pq = []
    costs = {}
    heapq.heappush(pq, (0, 1))
    while pq:
        cur_cost, cur_v = heapq.heappop(pq)
        if cur_v not in costs:
            costs[cur_v] = cur_cost
            for cost, next_v in graph[cur_v]:
                next_cost = cur_cost + cost
                heapq.heappush(pq, (next_cost, next_v))

    cost_values = list(costs.values())
    answer = cost_values.count(max(cost_values))
    return answer


print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
