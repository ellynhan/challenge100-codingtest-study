# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode('ascii'))
# atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

N, M = map(int, input().split())
arr =  [ [0 for i in range(M)] for _ in range(N)]
answer = [[ [0 for i in range(M)] for _ in range(N)] for _ in range(2)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]

for i in range(N):
    arr[i] = list(map(int, input()))

#원래대로
queue = deque()
queue.append((0,0,0))

answer[0][0][0] = 1
answer[1][0][0] = 1

while queue:

    x, y, count = queue.popleft()
    
    if x == N-1 and y == M-1 :
        break

    for i in range(4):
        cx = x + dx[i]
        cy = y + dy[i]
        
        if 0<= cx < N and 0<= cy < M: #범위 내의 값이면
            if arr[cx][cy] == 0 and answer[count][cx][cy] == 0: #길
                answer[count][cx][cy] = answer[count][x][y] + 1
                queue.append((cx,cy,count))
            elif arr[cx][cy] == 1 and count == 0 and answer[count+1][cx][cy] == 0:
                answer[count+1][cx][cy] = answer[count][x][y] + 1
                queue.append((cx,cy,count+1))
 

if answer[0][N-1][M-1] == 0 and answer[1][N-1][M-1] == 0:
    print(-1)
else:
    if answer[0][N-1][M-1] == 0:
        print(answer[1][N-1][M-1])    
    elif answer[1][N-1][M-1] == 0:   
        print(answer[0][N-1][M-1])    
    else:
        print(min(answer[0][N-1][M-1], answer[1][N-1][M-1]))      



