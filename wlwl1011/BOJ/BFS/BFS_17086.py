import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
dx = [-1, 1, 0, 0, -1, 1, -1, 1]
dy = [0, 0, -1, 1, -1, -1, 1, 1]

N, M = map(int, input().split())
arr = [ [ 0 for _ in range(M)] for _ in range(N)]


for i in range(N):
    arr[i] = list(map(int, input().split()))
answer = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0: #빈칸이면
            queue = deque()
            queue.append((i,j,0))
            visited = [ [ 0 for _ in range(M)] for _ in range(N)]
            while queue:
                x, y, cnt = queue.popleft()
                if arr[x][y] == 1:
                    answer = max(answer, cnt)
                    break
                for k in range(8):
                    tx = x + dx[k]
                    ty = y + dy[k]

                    if 0<= tx < N and 0 <= ty < M:
                        if not visited[tx][ty]:
                            visited[tx][ty] = 1
                            queue.append((tx,ty,cnt+1))

print(answer)

#1은 아기 상어가 있는 칸