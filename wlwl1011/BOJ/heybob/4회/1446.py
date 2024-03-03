import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
INF = int(1e9)
N, D = map(int, input().split())
d = [INF]*(D+1)
graph = [[] for _ in range(D+1)]
import heapq

def dikstra(start):
    q = []
    heapq.heappush(q,(0,start)) # 길이, 시작점

    while q:
        length, node = heapq.heappop(q)

        if length > d[node]:
            continue

        for load in graph[node]:
            cost = load[1] + length
            if cost < d[load[0]]:
                d[load[0]] = cost
                heapq.heappush(q,(cost, load[0]))



for i in range(D):
    graph[i].append([i+1,1])

for _ in range(N):
    start, end, length = map(int, input().split())
    if end > D:
        continue
    graph[start].append([end, length])


dikstra(0)
print(d[D])