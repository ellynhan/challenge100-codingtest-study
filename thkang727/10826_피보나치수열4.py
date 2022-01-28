#boj 10826
# DP
#



n = int(input())
dp = []

dp.append(0)
dp.append(1)

for i in range(n+1):
    if i<=1:
        pass
    else:
        dp.append(dp[i-2]+dp[i-1])

print(dp[n])
