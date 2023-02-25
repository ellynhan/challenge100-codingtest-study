import sys
from collections import deque
input = sys.stdin.readline


def move(x, y, dx, dy):
    moveCnt = 0
    while graph[x+dx][y+dy] != '#' and graph[x][y] != 'O':
        x += dx
        y += dy
        moveCnt += 1
    return x, y, moveCnt
        
def bfs(rx, ry, bx, by, cnt):
    q = deque()
    q.append((rx, ry, bx, by, cnt))
    visited[rx][ry][bx][by] = True
    
    while q:
        rx, ry, bx, by, cnt = q.popleft()
        
        if cnt > 10: break
        
        for i in range(4):
            nrx, nry, rcnt = move(rx, ry, dx[i], dy[i])
            nbx, nby, bcnt = move(bx, by, dx[i], dy[i])
            
            if graph[nbx][nby] == 'O': continue
            if graph[nrx][nry] == 'O': return cnt
           
        
            if nrx == nbx and nry == nby:
                if rcnt > bcnt:
                    nrx -= dx[i]
                    nry -= dy[i]
                else:
                    nbx -= dx[i]
                    nby -= dy[i]
            
            if visited[nrx][nry][nbx][nby]: continue
            visited[nrx][nry][nbx][nby] = True
            q.append((nrx, nry, nbx, nby, cnt+1))

    return -1
                
    
    
n, m = map(int, input().split())

graph = []
visited = [[[[False]*m for _ in range(n)] for _ in range(m)] for _ in range(n)]
for i in range(n):
    graph.append(list(input().rstrip()))
    for j in range(m):
        if graph[i][j] == 'R':
            rx, ry = i, j
        if graph[i][j] == 'B':
            bx, by = i, j

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

ans = bfs(rx, ry, bx, by, 1)
print(ans)
