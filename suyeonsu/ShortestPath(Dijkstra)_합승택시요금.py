import heapq

def solution(n, s, a, b, fares):
    graph = [[] for _ in range(n+1)]
    for x, y, c in fares:
        graph[x].append((y, c))
        graph[y].append((x, c))
        
    def dijkstra(srt, dest):
        visited = [0] * (n+1)
        distance = [1e9] * (n+1)
        q = []
        heapq.heappush(q, (0, srt))
        distance[srt] = 0
        while q:
            d, now = heapq.heappop(q)
            visited[now] = 1
            if distance[now] < d: continue
            for nxt, v in graph[now]:
                cost = d + v
                if not visited[nxt] and cost < distance[nxt]:
                    distance[nxt] = cost
                    heapq.heappush(q, (cost, nxt))
        return distance[dest]
    
    answer = 1e9
    for k in range(1, n+1):
        answer = min(answer, dijkstra(s, k) + dijkstra(k, a) + dijkstra(k, b))
    return answer
  
"""

[최단경로 문제]

- 종류
단일 출발 최단경로: 하나의 정점에서 출발해 나머지 모든 정점까지의 최단 경로를 찾는 문제
단일 도착 최단경로: 모든 정점으로부터 하나의 정점까지의 최단경로를 찾는 문제
단일 쌍 최단경로: 모든 정점 쌍들 사이의 최단 경로를 찾는 문제
    
- 주요 알고리즘
BFS(완전탐색 알고리즘): 가중치가 없거나 모든 가중치가 동일한 그래프에서 최단 경로 문제
다익스트라 알고리즘: 음이 아닌 가중치 그래프에서 단일 쌍, 단일 출발, 단일 도착 최단 경로 문제
벨만-포드 알고리즘: 가중치 그래프에서 단일 쌍, 단일 출발, 단일 도착 최단 경로 문제
플로이드-워셜 알고리즘: 모든 쌍 최단 경로 문제

"""
