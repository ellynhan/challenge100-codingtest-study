n = int(input())
a = list(map(int, input().split()))
dp = [0] * n
dp[0] = a[0]
for i in range(1, n):
    for j in range(i):
        dp[i] = max(dp[i], dp[j]+a[i]) if a[j] < a[i] else max(dp[i], a[i])
print(max(dp))
