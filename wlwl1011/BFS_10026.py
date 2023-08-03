# import sys, os, io, atexit
# import copy
# from collections import deque
# input = lambda: sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

queue = deque()
answer = []
N = int(input())
arr = [[ 0 for _ in range(N)] for _ in range(N)]
visited = [[ [0,0] for _ in range(N)] for _ in range(N)]

queue.append((0, 0, 1, 1))
visited[0][0] = [1,1]

for i in range(N):
    arr[i] = list(input())

while queue:

    print(queue)
    for i in range(N):
        for j in range(N):
            print(visited[i][j],end=' ')
        print()    

    x, y, cnt, rb_cnt = queue.popleft()
    
    for i in range(4):
        
        tx = x + dx[i]
        ty = y + dy[i]

        trb_cnt = rb_cnt 
        tcnt = cnt

        if not (0 <= tx < N and 0 <= ty < N):
            continue

        if visited[tx][ty][0]:
            #값이 있습니다만 ...
            if arr[tx][ty] != arr[x][y]: #값이 다르면
                if arr[x][y] == 'R' or arr[x][y] == 'G':
                    if arr[tx][ty] == 'R' or arr[tx][ty] == 'G':
                        visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]]
                    else:
                        visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]+1]
                else:
                    visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]+1]           
            continue

        while True:

            if not (0 <= tx < N and 0 <= ty < N):
                break
            if visited[tx][ty][0]:
                #값이 있습니다만 ...
                if arr[tx][ty] != arr[x][y]: #값이 다르면
                    if arr[x][y] == 'R' or arr[x][y] == 'G':
                        if arr[tx][ty] == 'R' or arr[tx][ty] == 'G':
                            visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]]
                        else:
                            visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]+1]
                    else:
                        visited[tx][ty] = [visited[tx][ty][0]+1,visited[tx][ty][1]+1]   
                break  
         
            if arr[x][y] != arr[tx][ty]:
                if arr[x][y] == 'R' or arr[x][y] == 'G':
                    if arr[tx][ty] == 'R' or arr[tx][ty] == 'G':
                            tcnt += 1    
                    else:
                            tcnt += 1
                            trb_cnt += 1    
                else:
                    tcnt += 1
                    trb_cnt += 1 
                visited[tx][ty] = [tcnt, trb_cnt]        
                break    
            visited[tx][ty] = [tcnt, trb_cnt]   
            tx += dx[i]
            ty += dy[i]
        if (0 <= tx < N and 0 <= ty < N):             
            queue.append((tx, ty, tcnt, trb_cnt))                 
            
                       

print(cnt, rb_cnt)