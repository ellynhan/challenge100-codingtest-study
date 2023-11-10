import sys
input = lambda : sys.stdin.readline().strip()
from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

T = int(input())

for _ in range(T):
    M, N, K = map(int, input().split())
    arr = [[0 for _ in range(M)] for _ in range(N)]
    visited = [[0 for _ in range(M)] for _ in range(N)]
    
    cnt = 0

    for _ in range(K):
        x, y = map(int, input().split())
        arr[y][x] = 1
    
    for i in range(N):
        for j in range(M):
            if visited[i][j] or not arr[i][j]:
                continue
            queue = deque()
            queue.append((i,j))
            visited[i][j] = 1
            cnt += 1
            while queue:
                r, c = queue.popleft()
                for m in range(4):
                    tr = r + dx[m]
                    tc = c + dy[m]

                    if 0 <= tr < N and 0 <= tc < M:
                        if not visited[tr][tc] and arr[tr][tc]:
                            visited[tr][tc] = 1
                            queue.append((tr,tc))
    print(cnt)

        
    