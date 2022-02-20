# https://www.acmicpc.net/problem/14502
from collections import deque
from copy import deepcopy
from itertools import combinations

def bfs_n_cnt(_map, virus):
    q = deque(virus)
    move = [(0,1), (1,0), (-1, 0), (0, -1)]
    while q:
        x, y = q.popleft()
        for dx, dy in move:
            nx = x + dx
            ny = y + dy
            if 0<=nx < N and 0<=ny <M and _map[nx][ny]==0:
                _map[nx][ny] = 2
                q.append((nx,ny))

    cnt = 0
    for i in range(N):
        for j in range(M):
            if _map[i][j] == 0:
                cnt+=1
    # print(cnt)
    return cnt


N, M = map(int, input().split(" "))
mp = []
virus = []
air = []
for _ in range(N):
    mp.append(list(map(int, input().split(" "))))

for i in range(N):
    for j in range(M):
        if mp[i][j] == 2:
            virus.append((i,j))
        elif mp[i][j] == 0:
            air.append((i,j))

comb = list(combinations(air, 3))
answer = 0
for l in comb:
    new_mp = deepcopy(mp)
    for x,y in l:
        new_mp[x][y] = 1
    answer = max(answer, bfs_n_cnt(new_mp, virus))
print(answer)