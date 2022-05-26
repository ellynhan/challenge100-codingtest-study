#
#   그래프 실버4
#   1388 바닥장식
#

import sys
from sys import stdin
sys.setrecursionlimit(10 ** 6) 

def dfs(x,y,verhor):
    
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    
    if check[x][y] == 1:
        if arr[x][y] != verhor:
            return False
        elif verhor == '-':
            check[x][y] = 0
            dfs(x, y - 1,verhor)
            dfs(x, y + 1,verhor)
        elif verhor == '|':
            check[x][y] = 0
            dfs(x-1, y,verhor)
            dfs(x+1, y,verhor)
            
        return True
    return False
        

n, m = map(int, stdin.readline().split())

arr = []
check = []
cnt = 0

#입력
for i in range(n):
    tmp = list(map(str, input()))
    arr.append(tmp)
    tmp = [1 for j in range(m)]    
    check.append(tmp)
    
#갯수 체크
for i in range(n):
    for j in range(m):
        if check[i][j] == 1:
            if arr[i][j] == "-":
                dfs(i,j,'-')
                cnt+=1
            elif arr[i][j] == '|':
                dfs(i,j,'|')
                cnt+=1
            
print(cnt)
