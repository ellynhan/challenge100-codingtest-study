# https://www.acmicpc.net/problem/2178
from collections import deque

N, M = map(int, input().split(" "))
miro = [[int(x) for x in input()] for _ in range(N)]
# print(miro)

move = [(1,0),(0,1),(-1,0),(0,-1)]
q = deque([(0,0,0)]) # x, y, move

answer = N*M

visit = [[False]*M for _ in range(N)]
while q:
    x, y, l = q.popleft()
    if x== N-1 and y == M-1:
        answer = min(answer, l)
    for dx, dy in move:
        nx = x+dx
        ny = y+dy
        if 0<=nx<N and 0<=ny<M and miro[nx][ny]==1:
            if not visit[nx][ny]:
                visit[nx][ny] = True
                q.append((nx,ny,l+1))

print(answer+1)