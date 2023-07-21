import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1,stdout.getvalue()))
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

global answer


def isBarrier(x, y):
    if arr[x][y] == '#':
        return True
    else:
        return False    

def isInNumber(x,y):
    if 0<= x < N and 0 <= y < M:
        return True
    else:
        return False

def move(r_x, r_y, b_x, b_y, depth):
    global answer
    # print(r_x, r_y, b_x, b_y)
    # print(arr[r_x][r_y],arr[b_x][b_y])
    if depth > 10:
        return

    if arr[r_x][r_y] == 'O' and arr[b_x][b_y] != 'O':
        answer = min(answer, depth)
        return 


    for i in range(4):

        #빨간구슬
        tr_x = r_x + dx[i]
        tr_y = r_y + dy[i]

        #파란 구슬
        tb_x = b_x + dx[i]
        tb_y = b_y + dy[i]
        #범위 벽


        #빨간 구슬 파란구슬 모두 범위가 아님
        if isInNumber(tr_x,tr_y)==0 and isInNumber(tb_x, tb_y)==0 : 
            continue
        #빨간 구슬 파란구슬 모두 범위 안에 있고
        elif isInNumber(tr_x,tr_y)==1 and isInNumber(tb_x, tb_y)==1 : 
            #가고자하는 곳이 모두 벽임
            if isBarrier(tr_x, tr_y)==1 and isBarrier(tb_x, tb_y)==1:
                continue
            #빨간구슬은 벽이고, 파란 구슬은 벽이 아닐때
            elif isBarrier(tr_x, tr_y) == 1 and isBarrier(tb_x, tb_y) == 0:
                    #빨간색은 기존의 위치를 유지하되 파란 구슬은 엄직여라
                if visited[tb_x][tb_y] == 0:   
                    visited[tb_x][tb_y] = 1 
                    move(r_x, r_y, tb_x, tb_y,depth+1)
                    visited[tb_x][tb_y] = 0
            #빨간 구슬은 벽이 아니고 파란 구슬은 벽일때        
            elif isBarrier(tr_x, tr_y) == 0 and isBarrier(tb_x, tb_y) == 1:   
                #파란색은 기존의 위치를 유지해라
                if visited[tr_x][tr_y] == 0:   
                    visited[tr_x][tr_y] = 1
                    move(tr_x, tr_y, b_x, b_y,depth+1)
                    visited[tr_x][tr_y] = 0
            else: #둘다 이동이 가능하다       
                if visited[tr_x][tr_y] == 0 and  visited[tb_x][tb_y] == 0:  
                    move(tr_x, tr_y, tb_x, tb_y,depth+1)
            #빨간 구슬만 범위안이면
        elif isInNumber(tr_x, tr_y) == 1 and isInNumber(tb_x, tb_y) == 0:     
            if isBarrier(tr_x, tr_y)==1:
                continue
            else:
                if visited[tr_x][tr_y] == 0:   
                    visited[tr_x][tr_y] = 1
                    move(tr_x, tr_y, b_x, b_y,depth+1)   
                    visited[tr_x][tr_y] = 0
        elif isInNumber(tr_x, tr_y) == 0 and isInNumber(tb_x, tb_y) == 1:             
            if isBarrier(tb_x, tb_y)==1:
                continue
            else:
                if visited[tb_x][tb_y] == 0:
                    visited[tb_x][tb_y] = 1
                    move(r_x, r_y, tb_x, tb_y,depth+1) 
                    visited[tb_x][tb_y] = 0


      

answer = int(1e9)
N, M = map(int, input().split()) #세로 가로
arr = [[0 for _ in range(M)] for _ in range(N)]
visited =  [[0 for _ in range(M)] for _ in range(N)]

red_x, red_y, blue_x, blue_y = 0, 0, 0, 0
for i in range(N):
    temp = input()
    arr[i] = temp
    for j in range(M):
        if temp[j] == 'R':
            red_x = i
            red_y= j
        elif temp[j] == 'B':
            blue_x = i
            blud_y = j
        elif temp[j] == '#':
            visited[i][j] = 1    

    
move(red_x, red_y, blue_x, blue_y, 0)

print(answer)
if answer > 10:
    print(-1)
else:
    print(answer)    
