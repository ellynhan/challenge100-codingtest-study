import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
N, M = int(input().split())

arr = [ [0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, input().split()))
   
queue = deque()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
count = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] == 2: #바이러스를 놓을 수 있는 칸이면
            visited = [ [0 for _ in range(N)] for _ in range(N)]
            queue.append((i,j,0))
            count += 1
            while queue:
                x, y, cnt = queue.popleft()

                for k in range(4):
                    tx = x + dx[k]
                    ty = y + dy[k]
                    if 0<= tx < N and 0 <= ty < N: 
                        if arr[tx][ty] != 1 and not visited[tx][ty]:#벽이 아니고 방문한적 없으면
                            visited[tx][ty] = visited[x][y] + 1

