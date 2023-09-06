import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import heapq
INF = int(1e9)


def digkstra(start):
    q = []
    #시작 노드로 가기 위한 최단 경로는 0으로 설정하여 큐에 삽입
    heapq.heappush(q,(0,start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist : #이미 처리된 적이 있는 노드라면 무시
            continue
        for i in graph[now]:
            cost = dist + i[1]
            #현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if i[0] >= len(distance) :
                continue
            if cost < distance[i[0]]:  
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))  


N, D = map(int,input().split())
#각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트 만들기
graph = [[] for i in range(D+1)]
#최단거리 테이블을 모두 무한으로 초기화
distance = [INF] * (D+1)

#일단 거리 1로 초기화.
for i in range(D+1):
    graph[i].append((i+1, 1))


for _ in range(N): #모든 간선에 대한 정보 받기
    a,b,c = map(int, input().split())
    if b <= D:
        graph[a].append((b,c))
#print(graph)
digkstra(0)
print(distance[D])