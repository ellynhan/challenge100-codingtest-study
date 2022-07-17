import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

n = int(input())

graph = [list(map(int, input().rstrip())) for _ in range(n)]
indivisualNumbering = []

totalNumbering = 0
cnt = 0


def dfs(x, y):
    global cnt
    
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    
    if graph[x][y] == 1:
        
        graph[x][y] = 0
        cnt += 1
        
        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        
        return True
    
    return False
        
for i in range(n):
    for j in range(n):
        if dfs(i, j) == True:
            totalNumbering += 1
            indivisualNumbering.append(cnt)
            cnt = 0
            

indivisualNumbering.sort()

print(totalNumbering)

for i in indivisualNumbering:
    print(i)