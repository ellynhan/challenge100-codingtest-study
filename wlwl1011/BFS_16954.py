import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

dx = [-1,1,0,0,-1,1,1,-1]
dy = [0,0,-1,1,-1,1,-1,1]

arr = [[ ['.' for _ in range(8)] for _ in range(8) ] for _ in range(9)]
visited = [[ [0 for _ in range(8)] for _ in range(8) ] for _ in range(9)]
queue = deque()
queue.append((7,0,0)) 
barrier = {}

for i in range(8):
    temp = list(input())
    arr[0][i] = temp
    for j in range(8):
        if temp[j] == '#':
            barrier[(i,j)] = 1

for i in range(9):
    for b_i, b_j in barrier.keys():
        cb_i = b_i + i
        if cb_i < 8:
            arr[i][cb_i][b_j] = '#'
            #arr[i][cb_i-1][b_j] = '.'


# for i in range(9):
#     print(i)
#     for j in range(8):
#         for k in range(8):
#             print(arr[i][j][k], end='')
#         print()
#     print()        
            
    



barrier = dict(sorted(barrier.items(), reverse=True))

# print(barrier)
count = 1
while queue:
    # print('--------')
    # print(queue)
    x, y, number = queue.popleft()
    # print(x,y,number)
    # for a in range(8):
    #     for b in range(8):
    #         print(arr[number][a][b],end='')
    #     print()     
    if arr[number][x][y] == '#': #혹시 지금 내가 있는 곳이 벽이 된건가 ..
        # print('Barrier!')
        continue
    if x == 0 and y == 7:
        print(1)
        exit()
    number += 1
    if number > 8:
        number = 8
             
    for i in range(8):
        cx = x + dx[i]
        cy = y + dy[i]

        if 0 <= cx < 8 and 0 <= cy < 8: #범위를 만족하는 값에 대해서만
            if arr[number-1][cx][cy] == '.' and not visited[number][cx][cy] : #벽이 아니면     
                visited[number][cx][cy] =  1
                queue.append((cx,cy, number))
    #현재 위치에 서 있을 수도 있다.
    queue.append((x,y,number))   
    #벽이여 움직여라!
    # arr을 돌면서 ... 밑으로 내려주면 ... 안될 것 같고 ...
    # 입력부터 그 위치를 기억해뒀다가 하나씩 내려주는 것이여       
    # copy_arr = [ a[:] for a in arr ] 
 
     


print(0)