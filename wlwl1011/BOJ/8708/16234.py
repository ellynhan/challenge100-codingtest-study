# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

#문제 이해 잘 못함 ㅠ
# bfs를 함수화 하는 것이 좋은 것 같음
graph = []
n,l,r = map(int,input().split())
for _ in range(n):
    graph.append(list(map(int,input().split())))

dx = [0,0,1,-1]
dy = [1,-1,0,0]
def bfs(a,b):
    q = deque()
    temp = []
    q.append((a,b))
    temp.append((a,b))
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] == 0:
                # 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
                if l<=abs(graph[nx][ny]-graph[x][y])<=r:
                    visited[nx][ny] = 1
                    q.append((nx,ny))
                    temp.append((nx,ny))
    return temp
            
result = 0
while 1:
    visited = [[0] * (n+1) for _ in range(n+1)]
    flag = 0
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                visited[i][j] = 1
                country = bfs(i,j)
                # 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
                if len(country) > 1:
                    flag = 1
                    # 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
                    number = sum([graph[x][y] for x, y in country]) // len(country)
                    for x,y in country:
                        graph[x][y] = number
    # 연합을 해체하고, 모든 국경선을 닫는다.
    if flag == 0:
        break
    result += 1
print(result)