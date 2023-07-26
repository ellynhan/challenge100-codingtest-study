import sys
n = int(input())
dp = [0]
dp += (list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(2, n+1):
    for j in range(1, (i//2) + 1):
        dp[i] = max(dp[i], dp[j]+dp[i-j])
    # 이렇게 하면 더 빠르다.
    # dp[i] = max([dp[j] + dp[i-j] for j in range((i//2) + 1)])
print(dp[n])