n = int(input())

dp = [0 for _ in range(3)]

dp[0] = 1
dp[1] = 1

for i in range(2,n+1):
    dp[2] = (dp[1] + dp[0]) % 15746
    dp[0] = dp[1]
    dp[1] = dp[2]
if n == 1:
    print(1)
else:
    print(dp[2])