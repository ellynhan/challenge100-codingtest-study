import sys

n = int(input())

inputData = [0] + list(map(int, sys.stdin.readline().rstrip().split()))

dp = [0 for _ in range(n+1)]
ans = 0
for i in range(1, n+1):
    if inputData[i] >= inputData[i-1]:
        dp[i] = dp[i-1] + 1
    else :
        dp[i] = 1
    ans = max(ans, dp[i])

dp[n] = 1
for i in range(n - 1, 0, -1):
    if inputData[i] >= inputData[i+1]:
        dp[i] = dp[i+1] + 1
    else :
        dp[i] = 1
    ans = max(ans, dp[i])
print(ans)