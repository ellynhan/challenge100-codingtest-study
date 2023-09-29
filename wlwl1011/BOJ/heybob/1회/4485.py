import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq
from collections import deque


dx = [-1,1,0,0]
dy = [0,0,-1,1]

def dikstra(x,y):
    q = []
    heapq.heappush(q,(arr[x][y],x,y))#금액 순으로 ..   

    while q:
        money, x, y = heapq.heappop(q)

        if money > distance[x][y]:
            continue

        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]

            if 0 <= tx < N and  0 <= ty < N:
                cost = money + arr[tx][ty]
                if cost < distance[tx][ty]:
                    distance[tx][ty] = cost
                    heapq.heappush(q,(cost,tx,ty))


index = 1
while True:
    N = int(input())
    if N== 0:
        break
    arr = []
    distance = [[int(1e9) for _ in range(N)] for _ in range(N)]
    for i in range(N):
        arr.append(list(map(int, input().split())))
    
    dikstra(0,0)
    # print('------')
    # for i in range(N):
    #     print(*distance[i])
    print("Problem ",index,": ",distance[N-1][N-1],sep='')
    index += 1

    
                