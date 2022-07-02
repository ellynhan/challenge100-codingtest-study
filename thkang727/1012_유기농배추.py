#
#   그래프 실버4
#   1388 바닥장식
#

import sys
from sys import stdin
sys.setrecursionlimit(10 ** 6) 

def dfs(x,y):

    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
        
    if check[x][y] == 0:
        if arr[x][y] != 1:
            return False
        else:
            check[x][y] = 1
            dfs(x, y - 1)
            dfs(x, y + 1)
            dfs(x-1, y)
            dfs(x+1, y )
        return True
    return False


t = int(stdin.readline())
for q in range(t):
    m, n, k = map(int, stdin.readline().split())
    arr = []
    check = []
    cnt = 0

    for i in range(n):
        tmp = [0 for j in range(m)]
        arr.append(tmp)
        ttmp= tmp.copy()
        check.append(ttmp)
    #입력
    for i in range(k):
        x, y = map(int, stdin.readline().split())
        arr[y][x] = 1

    #갯수 체크
    for i in range(n):
        for j in range(m):
            if check[i][j]==0:
                #print(arr[i][j])
                if arr[i][j] == 1:
                    dfs(i,j)
                    cnt+=1

    print(cnt)
