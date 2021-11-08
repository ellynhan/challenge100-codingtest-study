# 백준 1012번 유기농 배추
# 실버 2
import heapq


T = int(input())
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def elle(x, y):
    h = [[x, y]]
    while h:
        a, b = heapq.heappop(h)
        for i in range(4):
            ax = a+dx[i]
            ay = b+dy[i]
            if 0<=a<M and 0<=b<N and [ax, ay] in coord:
                coord.remove([ax, ay])
                heapq.heappush(h, [ax, ay])


for _ in range(T):
    cnt = 0
    M, N, K = map(int, input().split())
    coord = []
    for _ in range(K):
        x, y = map(int, input().split())
        coord.append([x, y])
    while coord:
        a, b = coord[0]
        del coord[0]
        elle(a, b)
        cnt += 1
    print(cnt)
