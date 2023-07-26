# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode('ascii'))
# atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

N, M = map(int, input().split())
arr =  [ [0 for i in range(M)] for _ in range(N)]

answer = [ [0 for i in range(M)] for _ in range(N)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
barrier = {}
for i in range(N):
    arr[i] = list(map(int, input()))
    for j in range(M):
        if arr[i][j] == 1: #벽인 곳을 기억해두자
            barrier[(i,j)] = 1



#원래대로
queue = deque()
queue.append((0,0))
answer[0][0] = 1
min_answer = int(1e9)
while queue:
    x, y = queue.popleft()
   
    for i in range(4):
        cx = x + dx[i]
        cy = y + dy[i]

        if 0<= cx < N and 0<= cy < M: #범위 내의 값이면
            if arr[cx][cy] == 0 and answer[cx][cy] == 0: #길이고 안 간 길이라면
                answer[cx][cy] = answer[x][y] + 1
                queue.append((cx,cy))


if  answer[N-1][M-1] != 0:    
    min_answer = min(min_answer, answer[N-1][M-1]) 


#벽을 부수자
for bx, by in barrier.keys():
    
    arr[bx][by] = 0 #벽을 길로 만들고
    # print('------------')
    # for index_i in range(N):
    #     print(arr[index_i])
        
    new_answer = [ [0 for i in range(M)] for _ in range(N)]
    queue = deque()
    queue.append((0,0))
    new_answer[0][0] = 1

    while queue:
        x, y = queue.popleft()
       
        for i in range(4):
            cx = x + dx[i]
            cy = y + dy[i]

            if 0<= cx < N and 0<= cy < M: #범위 내의 값이면
                if arr[cx][cy] == 0 and new_answer[cx][cy] == 0: #길이고 안 간 길이라면
                    new_answer[cx][cy] = new_answer[x][y] + 1
                    queue.append((cx,cy))

    arr[bx][by] = 1
    if new_answer[N-1][M-1] != 0:
        min_answer = min(min_answer, new_answer[N-1][M-1])
    

if min_answer == int(1e9):
    print(-1)
else:
    print(min_answer)    