import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import heapq
INF = int(1e9)

N = int(input())

graph = [[] for _ in range(N)]
distance = [INF] * (N)
for i in range(N):
    index = 0
    for j in map(int, input().split()):
        if j == 0:
            j = INF
        graph[i].append((index,j))
        index += 1

# for i in range(N):
#     print(graph[i])


#print(graph)
def digkstra(start):
    q = []
    #시작 노드로 가기 위한 최단 경로는 0으로 설정하여 큐에 삽입
    heapq.heappush(q,(0,start))
    distance[start] = 0
    while q:
        # print()
        # print('pop!!')
        # print('q : ',q)      
        # print('distance: ' , distance) 
        dist, now = heapq.heappop(q)

        if distance[now] < dist : #이미 처리된 적이 있는 노드라면 무시
            continue
        # print()
        # print('dist:', dist)
        # print('now: ', now)
        # print(graph[now])
        for i in graph[now]:
            cost = dist + i[1]
            #현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            # print(i)
            # print('dist + i[1] = cost : ',dist ,' + ',i[1] , ' = ', cost )
            # print('distance[i[0]] : ',distance[i[0]])
            if cost < distance[i[0]]:  
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))  
         

for i in range(N):
    digkstra(i)

    print(distance)

