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
    if 0< x < N-1 and 0 <= y < M-1:
        return True
    else:
        return False

def isHold(x,y):
    if arr[x][y] == 'O':
        return True
    else:
        return False

def move(r_x, r_y, b_x, b_y, direction, depth):
    check_red_change = False
    check_blue_change = False
    if depth > 10:
        return
    # print("------------")
    # print('depth:', depth)
    # print('direction:', direction)
    # print('red: ' ,r_x, r_y )
    # print('blue: ', b_x, b_y )
    global answer

    red_in_hold = False
    blue_in_hole = False
    # print('moveing~')   

    while True:
        tr_x = r_x + dx[direction]
        tr_y = r_y + dy[direction]

        if isInNumber(tr_x, tr_y) == False or isBarrier(tr_x, tr_y) == True:
            break
        elif isHold(tr_x, tr_y):
            r_x = 0
            r_y = 0
            red_in_hold = True
            break
        elif tr_x == b_x and tr_y == b_y:
            break
        else:
            check_red_change = True
            r_x = tr_x
            r_y = tr_y
            visited[r_x][r_y] = 1
            
    while True:    
        tb_x = b_x + dx[direction]
        tb_y = b_y + dy[direction]

        if isInNumber(tb_x, tb_y) == False or isBarrier(tb_x, tb_y) == True:
            break
        elif isHold(tb_x, tb_y):
            b_x= 0
            b_y =0
            blue_in_hole = True
            break
        elif tb_x == r_x and tb_y == r_y:
            break
        else:
            check_blue_change = True
            b_x = tb_x
            b_y = tb_y
            visited[b_x][b_y] = 1

    # print('red: ' ,r_x, r_y )
    # print('blue: ', b_x, b_y )     
    if red_in_hold == True and blue_in_hole == False:
        answer = min(answer, depth)
        return
    elif red_in_hold == True and blue_in_hole == True:
        answer = -1
        return
 
    
    if not check_red_change and not check_blue_change: #변경된거 없음
        return

    for i in range(4):      
        tr_x = r_x + dx[i]
        tr_y = r_y + dy[i]

        if isInNumber(tr_x, tr_y) == False or isBarrier(tr_x, tr_y) == True:
            continue
        if visited[tr_x][tr_y] == 0:
            move(r_x, r_y, b_x, b_y, i, depth+1) 
                   
      

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
            blue_y = j
            # print(i,j)
        elif temp[j] == '#':
            visited[i][j] = 1    

for i in range(4):    
    # print('\n',i,"start\n")
    visited =  [[0 for _ in range(M)] for _ in range(N)]
    move(red_x, red_y, blue_x, blue_y,  i, 1)


# print('answer is..... ')
# print(answer)
if answer > 10:
    print(-1)
else:
    print(answer)    
