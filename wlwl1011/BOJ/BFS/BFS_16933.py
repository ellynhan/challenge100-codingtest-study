import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
#이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 
# 이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M, K = map(int, input().split())

arr = [ [0 for _ in range(M)] for _ in range(N)]
visited = [[ [0 for _ in range(M)] for _ in range(N)] for _ in range(K+1)]

#값을 입력 받자
for i in range(N):
    arr[i] = list(map(int, input()))

queue = deque()
queue.append((0,0,0,True,0)) #x, y, count, 낮, 기다림

visited[0][0][0] = 1

while queue:
    # print(queue)
    # for i in range(K+1):
    #     print(i)
    #     for j in range(N):
    #         print(visited[i][j])
    x, y, count, time, wait = queue.popleft()
    

    for i in range(4):
        cx = x + dx[i]
        cy = y + dy[i]

        if 0 <= cx < N and 0 <= cy < M:
            if visited[count][cx][cy]:
                continue
            if arr[cx][cy] == 0: #벽이 아니면
                visited[count][cx][cy] = visited[count][x][y] + 1 + wait
                queue.append((cx, cy, count, not time, 0))
            elif arr[cx][cy] == 1: #벽이면
                #낮이면    
                if (not time) == False and count < K:
                    if not visited[count+1][cx][cy]:
                        #벽 부수셈
                        visited[count+1][cx][cy] = visited[count][x][y] + 1 + wait
                        queue.append((cx, cy, count+1, not time, 0))
                #밤이셈?
                elif(not time) == True and count < K:
                    if not visited[count+1][cx][cy]:
                        queue.append((x, y, count, not time, wait + 1))

count = 0
answer = int(1e9)
for i in range(K+1):
    # print(i)
    # for j in range(N):
    #     print(visited[i][j])
    if visited[i][N-1][M-1] == 0:
        count +=1
    else:
        answer = min(answer,visited[i][N-1][M-1])

if count == K+1:
    print(-1)
else:
    print(answer)    




