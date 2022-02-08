#
#   boj 11660
#   dp.
# #

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pyo = []


if n >=1 and m>=1 :
    for i in range(n):
        pns = list(map(int, input().split()))
        pyo.append(pns)

    dp = [[0 for i in range(n + 1)] for i in range(n + 1)]

    for i in range(n):
        for j in range(n):
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j] + pyo[i][j]
    
    
    for i in range(m):
        xa,ya,xb,yb = map(int, input().split())
        ans = dp[xb][yb] - (dp[xa-1][yb]+dp[xb][ya-1]-dp[xa-1][ya-1])
        print(ans)
    

