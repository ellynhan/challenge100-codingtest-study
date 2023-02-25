import sys
import heapq
input = sys.stdin.readline

v, e = map(int, input().split())
graph = {i:[] for i in range(1, v+1)}
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

cost = 0
visited = set()
hq = [(0, 1)]
while hq:
    if len(visited) == v: break
    c, i = heapq.heappop(hq)
    if i not in visited:
        visited.update([i])
        cost += c
        for edge in graph[i]:
            heapq.heappush(hq, edge)
print(cost)

""" 
[Prim MST 알고리즘]
시작 정점에서부터 출발하여 신장트리 집합을 단계적으로 확장 해나가는 방법

정점 선택을 기반으로 하는 알고리즘이다.
이전 단계에서 만들어진 신장 트리를 확장하는 방법이다.

[과정]
  시작 단계에서는 시작 정점만이 MST(최소 비용 신장 트리) 집합에 포함된다.
  앞 단계에서 만들어진 MST 집합에 인접한 정점들 중에서 최소 간선으로 연결된 정점을 선택하여 트리를 확장한다. 즉, 가장 낮은 가중치를 먼저 선택한다.
  위의 과정을 트리가 (N-1)개의 간선을 가질 때까지 반복한다.
"""
