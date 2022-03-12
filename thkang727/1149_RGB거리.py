#
#   1149
#   dp
# #


n = int(input())

pyo = []
dp = []

for _ in range(n):
    tmp = []
    r,g,b = map(int,input().split())
    tmp.append(r)
    tmp.append(g)
    tmp.append(b)
    pyo.append(tmp)
    dp.append([0,0,0])

dp[0][0] = pyo[0][0]
dp[0][1] = pyo[0][1]
dp[0][2] = pyo[0][2]

for _ in range(1,n):
    dp[_][0] = min(dp[_-1][1],dp[_-1][2]) + pyo[_][0]
    dp[_][1] = min(dp[_-1][0],dp[_-1][2]) + pyo[_][1]
    dp[_][2] = min(dp[_-1][0],dp[_-1][1]) + pyo[_][2]

print(min(dp[n-1]))
