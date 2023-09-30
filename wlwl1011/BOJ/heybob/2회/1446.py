import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq

INF = int(1e9)
N, D = map(int, input().split())
arr = [[] for i in range(D+1)]
distance = [INF]*(D+1) 

def dikstra(start):
    q = []
    heapq.heappush(q,(0,start)) #거리를 기준으로 정렬
    distance[start] = 0
    
    while q:
        
        dist, now = heapq.heappop(q)
        
        if distance[now] < dist:
            continue
        for i in arr[now]:
            if i[1] + dist < distance[i[0]]: 
                distance[i[0]] = i[1] + dist
                heapq.heappush(q,(i[1] + dist,i[0]))

for i in range(D):
    arr[i].append((i+1,1))


for _ in range(N):
    start, end, length = map(int, input().split())
    if end <= D:
        arr[start].append((end, length))





    
dikstra(0)

print(distance[D])