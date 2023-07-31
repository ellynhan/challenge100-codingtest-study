import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

#거울의 개수를 어떻게 카운트 하느냐



# def dfs(x, y, direction):
#     #그 방향 그대로 갈래? 아니면 .. 방향을 틀래 ...?
#     cx = x + dx[direction]
#     cy = y + dy[direction]

#     if 0 <= cx < H and 0 <= cy < W: 
#         if arr[cx][cy] != '*': #벽이 아니면  
#             dfs(x,y,direction) #직진하셈!
#             #근데 꼭 직진해야하는 건 아니긴한데 ..
  


W, H  = map(int, input().split())        
arr = [ ['' for _ in range(W)] for _ in range(H) ]
can = set()
queue = deque()
visited = [ [int(1e9) for _ in range(W)] for _ in range(H) ]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(H):
    arr[i] = list(input()) #일단 냅다 집어넣자
    for j in range(W):
        if arr[i][j] == 'C': 
            can.add((i,j))
first_x,first_y = can.pop()
last_x, last_y = can.pop()

queue.append((first_x, first_y))

visited[first_x][first_y] = 0
while queue:

    x, y= queue.popleft()
    
    for i in range(4):        
        tx = x + dx[i]
        ty = y + dy[i]
        while True:
            
            if not ( 0 <= tx < H and 0 <= ty < W ):
                break
            if arr[tx][ty] == "*" :
                break
            if visited[tx][ty] < visited[x][y] + 1:
                break
            queue.append((tx, ty))
            visited[tx][ty] = visited[x][y] + 1
            tx += dx[i]    
            ty += dy[i]
        # for k in range(H):
        #     print(visited[k])    

print(visited[last_x][last_y]-1)            
