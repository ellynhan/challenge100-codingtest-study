import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())
max = 10**5
dis = [0] * (max + 1)
q = deque()

q.append(n)


def bfs():
    while q:
        x = q.popleft()
        
        if x == k:
            print(dis[x])
            break
        
        for nx in (x-1, x+1, x*2):
            
            if 0 <= nx <= max and dis[nx] == 0:
                dis[nx] = dis[x] + 1
                q.append(nx)
    
    

bfs()
