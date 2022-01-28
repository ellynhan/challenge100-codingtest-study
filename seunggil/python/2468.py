import sys
from collections import deque

near = [(1,0),(-1,0),(0,1),(0,-1)]

n = int(input())

inputData = []

for _ in range(n):
    inputData.append(list(map(int,sys.stdin.readline().rstrip().split())))

answer = 0
for height in range(101):
    local = [[True if inputData[a][b] > height else False for b in range(n)] for a in range(n)]
    
    ans = 0
    dfs = deque()
    for a in range(n):
        for b in range(n):
            if local[a][b] : 
                local[a][b] = False
                dfs.append((a,b))
                ans += 1
                while len(dfs) :
                    now = dfs.pop()
                    for d in near:
                        next = (now[0]+ d[0], now[1]+ d[1])
                        if 0 <= next[0] < n and 0 <= next[1] < n and local[next[0]][next[1]]:
                            local[next[0]][next[1]] = False
                            dfs.append(next)
    answer = max(answer, ans)
print(answer)