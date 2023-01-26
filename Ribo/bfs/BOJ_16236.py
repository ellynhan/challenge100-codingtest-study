import sys
import heapq
input = sys.stdin.readline


def bfs(x, y):
    global baby, time, eat, fish
    graph[x][y] = 0
    while fish:
        pq = []
        heapq.heappush(pq, (0, x, y))
        visited = [[False]*n for _ in range(n)]
        visited[x][y] = True
        flag = False
        while pq:
            dist, x, y = heapq.heappop(pq)
            if graph[x][y] != 0 and graph[x][y] < baby:
                flag = True
                graph[x][y] = 0
                time += dist
                eat += 1
                fish -= 1
                if eat == baby:
                    baby += 1
                    eat = 0
                break
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= n or visited[nx][ny]: continue
                if graph[nx][ny] > baby: continue
                visited[nx][ny] = True
                nextDist = dist + 1
                heapq.heappush(pq, (nextDist, nx, ny))
        
        if flag == False:
            return
        
                    
    
n = int(input())
graph = []
pq = []
fish = 0
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        if graph[i][j] == 9:
            sx, sy = i, j
        elif graph[i][j]:
            fish += 1
            
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

baby = 2
time = 0
eat= 0

bfs(sx, sy)
print(time)
