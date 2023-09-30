import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

M, N = map(int, input().split())
visited = [[-1 for _ in range(N)] for _ in range(M)] 
arr = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x,y):
    
    if x == M-1 and y == N-1:
        return 1

    if visited[x][y] != -1: #이미 방문한 적이 있다면
        return visited[x][y]
    
    way = 0
    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]

        if 0 <= tx < M and 0 <= ty < N:
            if arr[tx][ty] < arr[x][y]:
                way += dfs(tx,ty)
    visited[x][y] = way
    return visited[x][y]            



for _ in range(M):
    arr.append(list(map(int, input().split())))
ans = 0



print(dfs(0,0))

for i in range(M):
    print(visited[i])