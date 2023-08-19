
import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
from itertools import combinations

N, M = map(int,input().split())

def isComplete(visited,virus):
    for i in range(N):
        for j in range(N):
            if arr[i][j] == 1:
                continue
            else:    
                if visited[i][j]:
                    continue
                elif (i,j) in virus:
                    continue
                else:
                    return False    
       
    return True                



arr = [ [0 for _ in range(N)] for _ in range(N)]
virus = []
for i in range(N):
    arr[i] = list(map(int, input().split()))
    for j in range(N):
        if arr[i][j] == 2:
            virus.append((i,j))

virus_list = list(combinations(virus,M))   

#print(virus_list)
queue = deque()
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 1e9
for virus in virus_list:
    visited = [ [0 for _ in range(N)] for _ in range(N)]
    for i in virus:
        queue.append(i)
    
    time = 0
    while queue:
        # print()
        # for index_i in range(N):
        #     for index_j in range(N):
        #         print(visited[index_i][index_j],end=' ')
        #     print()    
        x, y = queue.popleft()
        for t in range(4):
            tx = x + dx[t]
            ty = y + dy[t]
            if 0<= tx < N and 0 <= ty < N: 
                if arr[tx][ty] != 1 and not visited[tx][ty] and (tx,ty) not in virus:#벽이 아니고 방문한적 없으면
                    visited[tx][ty] = visited[x][y] + 1
                    queue.append((tx,ty))
                    time = max(time, visited[tx][ty])
    #print(time)               

    if isComplete(visited,virus):
        #print(time)
        answer = min(answer, time)             

if answer == 1e9:
    print(-1)
else:
    print(answer)    
