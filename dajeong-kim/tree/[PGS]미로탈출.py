from collections import deque

# 가려는 곳이 유효한지 판단 (가로 세로 한계를 넘지 않고, X가 아닐때 True)
def is_valid (ny, nx, n, m, maps):
        return 0<=nx<m and 0<=ny<n and maps[ny][nx] != "X"

# visited : 이미 방문한 곳인지 판단
# 방문하지 않은 좌표일 경우 -> 덱에 추가
def append_to_queue(ny, nx, k, time, visited, q):
    if not visited[ny][nx][k]:
        visited[ny][nx][k] = True
        q.append((ny, nx, k, time+1))

def solution(maps):
    n, m = len(maps), len(maps[0])
    visited = [[[False for _ in range(2)] for _ in range(m)] for _ in range(n)]
    
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    q = deque()
    end_y, end_x = -1, -1
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] == "S":
                q.append((i,j,0,0))
                visited[i][j][0] = True
            if maps[i][j] == "E":
                end_y, end_x = i, j
    
    while q:
        y, x, k, time = q.popleft()
        
        if y == end_y and x == end_x and k == 1:
            return time
        
        # 가능한 네 방향으로 모두 test
        # 너비 우선 탐색 (최단 경로 보장)
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            
            if not is_valid (ny, nx, n, m, maps):
                continue
            
            if maps[ny][nx] == "L":
                append_to_queue(ny, nx, 1, time, visited, q)
            
            else:
                append_to_queue(ny, nx, k, time, visited, q)
    
    # 모든 q의 원소를 지났음에도 k==1이 아니거나 마지막 좌표에 도착하지 못했을 경우
    return -1
    
    