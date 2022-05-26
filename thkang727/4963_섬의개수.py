#
#   그래프 실버2
#   4963 섬의 갯수
#

import sys
from sys import stdin
sys.setrecursionlimit(10 ** 6) 

def dfs(x,y,w,h):

    if x <= -1 or x >= w or y <= -1 or y >= h:
        return False
        
    if check[x][y] == 0:
        if arr[x][y] != 1:
            return False
        else:
            check[x][y] = 1
            dfs(x, y - 1,w,h)
            dfs(x, y + 1,w,h)
            dfs(x-1, y,w,h)
            dfs(x+1, y ,w,h)
            dfs(x-1, y-1,w,h)
            dfs(x-1, y+1,w,h)
            dfs(x+1, y-1,w,h)
            dfs(x+1, y+1,w,h)
        return True
    return False



while True:
    w,h = map(int, stdin.readline().split())
    if w == 0 and h == 0:
        break
    arr = []
    check = []
    cnt = 0
    for i in range(h):
        tmp = list(map(int, stdin.readline().split()))
        arr.append(tmp)
        ttmp = [0 for j in range(w)]
        check.append(ttmp)
    

    #갯수 체크
    for i in range(h):
        for j in range(w):
            if check[i][j]==0:
                #print(arr[i][j])
                if arr[i][j] == 1:
                    dfs(i,j,h,w)
                    cnt+=1

    print(cnt)
