# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
# atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

dx = [-1,0,1,0]
dy = [0,1,0,-1]

N, M = map(int, input().split())
r, c, d = map(int, input().split())

arr = [[0 for _ in range(M)] for _ in range(N) ]

for i in range(N):
    arr[i] = list(map(int, input().split()))

cnt = 0 

while True:
    
    #현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    if arr[r][c] == 0:
        arr[r][c] = -1 #청소
        cnt += 1
        
    #현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는지 확인
    flag = True
    for i in range(4):
        tr = r + dx[i]
        tc = c + dy[i]     

        if 0 <= tr < N and 0 <= tc < M:
            if arr[tr][tc] == 0: #청소되지 않았다면,
                flag = False #청소되지 않은 곳 존재
                break

    if flag: #청소 다되었음
        #바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        if d == 0:
            tr = r + dx[2]
            tc = c + dy[2]
        elif d == 1:
            tr = r + dx[3] 
            tc = c + dy[3]
        elif d == 2:
            tr = r + dx[0]
            tc = c + dy[0]
        elif d == 3:
            tr = r + dx[1]
            tc = c + dy[1]

        if 0 <= tr < N and 0 <= tc < M:
            if arr[tr][tc] != 1: #벽이 아니면
                r,c,d = tr,tc,d
            else:#벽이면
                break          
    else:
        d -=1 #반시계 방향 회전
        if d < 0:
            d = 3
        #바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        check_r = r + dx[d]
        check_c = c + dy[d]    
        if arr[check_r][check_c] == 0:
            r,c,d = check_r,check_c,d                                            


print(cnt)    



