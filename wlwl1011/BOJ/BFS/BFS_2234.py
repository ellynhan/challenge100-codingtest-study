# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode('ascii'))
# atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

N, M = map(int, input().split())
arr = [[0 for _ in range(N)] for _ in range(M)]
visited = [[0 for _ in range(N)] for _ in range(M)]
broken_visited = dict()
queue = deque()

for i in range(M):
    arr[i] = list(map(int, input().split()))

# 1 - 서, 2 - 북, 4 - 동, 8 - 남
cnt = [0 for i in range(M*N+1)]
index = 1
for total_i in range(M):
    for total_j in range(N):
        if not visited[total_i][total_j]:
            queue.append((total_i,total_j))
            visited[total_i][total_j] = index
            cnt[index] = 1
            #print(total_i+1,total_j+1)
            #print(index)
            while queue:
                x, y = queue.popleft()
                for i in range(4):
                    if  (arr[x][y] & 1<<i) != 1<<i : 
                        tx = x + dx[i]
                        ty = y + dy[i]
                        if 0 <= tx < M and 0 <= ty < N:
                            if not visited[tx][ty]:
                                visited[tx][ty] = index
                                cnt[index] += 1
                                queue.append((tx,ty))
                    else:
                        #만약 벽이었는데    
                        tx = x + dx[i]
                        ty = y + dy[i]
                        if 0 <= tx < M and 0 <= ty < N:
                            #같은 index도 아니고, 딕셔너리에 저장된 것도 아니면 일단 냅다 저장해라!
                            if visited[tx][ty] != index and not (visited[tx][ty],index) in broken_visited:
                                broken_visited[(visited[tx][ty],index)] = 1       
            index += 1
                              
total_room_num = 0
for i in range(1,M*N+1):
    if cnt[i] == 0:
        break   
    total_room_num += 1
print(total_room_num)                   
print(max(cnt))
max_broken = 0
for index1, index2 in broken_visited.keys():
    max_broken = max(max_broken, cnt[index1]+cnt[index2])
print(max_broken)