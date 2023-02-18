import sys
from collections import deque
import copy
input = sys.stdin.readline
sys.setrecursionlimit(10**8)


def findSafeArea(copyGraph):
    safeArea = 0
    for i in range(n):
        for j in range(m):
            if copyGraph[i][j] == 0:
                safeArea += 1
    return safeArea

def bfs(copyGraph):
    q = deque(virus)
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and  0 <= ny < m:
                if copyGraph[nx][ny] == 0:
                    copyGraph[nx][ny] = 2
                    q.append((nx, ny))    
        
def bt(cnt, idx):
    global ans
    if cnt == 3:
        safeArea = 0
        copyGraph = copy.deepcopy(graph)
        bfs(copyGraph)
        safeArea = findSafeArea(copyGraph)
        if ans < safeArea:
            ans = safeArea
        return

    for i in range(idx, n*m):
        x, y = i//m, i%m
        if graph[x][y] == 0:
            graph[x][y] = 1
            bt(cnt+1, i+1)
            graph[x][y] = 0
        
n, m = map(int, input().split())

graph = []
virus = deque()
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(m):
        if graph[i][j] == 2:
            virus.append((i, j))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

ans = 0
bt(0, 0)
print(ans)
