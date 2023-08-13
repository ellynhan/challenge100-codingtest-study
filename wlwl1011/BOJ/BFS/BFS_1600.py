import sys, io, atexit, os
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

queue = deque()

dx = [-1,1,0,0]
dy = [0,0,-1,1]

nx = [-2,-2,2,2,-1,-1,1,1]
ny = [-1,1,-1,1,-2,2,-2,2]

K = int(input()) #원숭이는 K 번만 움직일 수 있다.
W, H = map(int, input().split())
if W == 1 and H == 1:
    temp = int(input())
    if temp == 0:
        print(0)
    else:
        print(-1)
    exit()        
arr = [[ 0 for _ in range(W)] for _ in range(H)]
visited = [[[ 0 for _ in range(W)] for _ in range(H)] for _ in range(K+1)]
for i in range(H):
    arr[i] = list(map(int, input().split()))
    #0은 평지
    #1은 장애물
    #말은 장애물을 뛰어넘을 수 있고.. 원숭이는 못함

queue.append((0,0,0))
flag = True
while queue:
    x, y, check = queue.popleft()
    #print(x,y,check)

    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]
        if 0 <= tx < H and 0 <= ty < W:
            if not visited[check][tx][ty] and not arr[tx][ty]: #방문한 적도 없고 장애물도 아니다.
                visited[check][tx][ty] = visited[check][x][y]+ 1
                queue.append((tx,ty,check))
    for i in range(8):
        tx = x + nx[i]
        ty = y + ny[i]
        if 0 <= tx < H and 0 <= ty < W:
            if check >= K:
                continue
            if not visited[check+1][tx][ty] and not arr[tx][ty]: #방문한 적도 없고 장애물도 아니다.
                visited[check+1][tx][ty]= visited[check][x][y] + 1
                queue.append((tx,ty,check+1))
answer = int(1e9)
for i in range(K+1):
    if visited[i][H-1][W-1] != 0:
        answer = min(answer, visited[i][H-1][W-1])

if answer == int(1e9):
    print(-1)
else:
    print(answer)    

    

