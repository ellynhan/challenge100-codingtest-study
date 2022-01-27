n = int(input())

inputData = list(map(int, input().split()))

dp = [i for i in inputData]
ans = max(dp[0], dp[1])
for i in range(2,n):
    for j in range(i-1):
        dp[i] = max(dp[i], inputData[i]+inputData[j])
        ans = max(ans, dp[i])
print(ans)