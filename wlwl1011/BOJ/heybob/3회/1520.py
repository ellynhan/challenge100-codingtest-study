import sys
sys.setrecursionlimit(10**8)
input = lambda : sys.stdin.readline().rstrip('\r\n')

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def findRoad(x,y):

    if x == M-1 and y == N-1:
        return 1
    
    if visited[x][y] != -1: #조건이 안되서 못간 경우를 포함시키기 위함! 
        return visited[x][y]
    ways = 0
    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]

        if 0 <= tx < M and 0 <= ty < N:
            if arr[tx][ty] < arr[x][y]:
                ways += findRoad(tx,ty)
    visited[x][y] = ways
    # print(x,y)
    # for i in range(M):
    #     print(*visited[i])
    return visited[x][y]            

    


M, N = map(int, input().split())
arr = []
visited = [[-1 for _ in range(N)] for _ in range(M)]
for _ in range(M):
    arr.append(list(map(int, input().split())))



print(findRoad(0,0))




