from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def solution(maps):
    answer = 0
    n = 0
    for i in maps:
        n += 1
    m = 0    
    for i in maps[0]:
        m += 1
    #print(n,m)    
    #n과 m 의 개수를 구해 visited를 할당한다.    
    visited = [ [0 for _ in range(m)] for _ in range(n)]
    
    queue = deque()
    queue.append((0,0))
    visited[0][0] = 1
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]
            if 0 <= tx < n and 0 <= ty < m:
                if maps[tx][ty]: #벽이 아니면..
                    if not visited[tx][ty]:
                        visited[tx][ty] = visited[x][y] + 1
                        queue.append((tx,ty))
        
    answer = visited[n-1][m-1]    
    if answer == 0:
        answer = -1
    return answer