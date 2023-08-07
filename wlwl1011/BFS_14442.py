import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M, K = map(int, input().split())
visited = [ [ [ 0 for _ in range(M)] for _ in range(N) ] for _ in range(K+1)]
arr = [ [ 0 for _ in range(M)] for _ in range(N) ]

for i in range(N):
    arr[i] = list(map(int, input()))

queue = deque()

visited[0][0][0] = 1
visited[1][0][0] = 1 

queue.append((0,0,0))

while queue:
    x, y, count = queue.popleft()
    if x == N-1 and y == M-1:
        break
    for i in range(4):
        cx = x + dx[i]
        cy = y + dy[i]

        if 0 <= cx < N and 0 <= cy < M:
            if arr[cx][cy] == 0 and visited[count][cx][cy] == 0:
                visited[count][cx][cy] = visited[count][x][y] + 1
                queue.append((cx,cy,count))
            elif arr[cx][cy] == 1 and count < K and visited[count+1][cx][cy] == 0:
                visited[count+1][cx][cy] = visited[count][x][y] + 1  
                queue.append((cx,cy,count+1))

count = 0
answer = int(1e9)
for i in range(K+1):
    
    if visited[i][N-1][M-1] == 0:
        count += 1
    else:
        answer = min(answer, visited[i][N-1][M-1])

if count == (K+1):
    print(-1)
else:
    print(answer)    
        

