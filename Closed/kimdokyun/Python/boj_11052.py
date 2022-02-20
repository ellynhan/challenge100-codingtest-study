N = int(input())
dp = []
nums = list(map(int,input().split()))
for i in range(N):
    dp.append(nums[i])
    for j in range(i):
        dp[i] = max(dp[i],dp[j]+dp[i-j-1])
print(dp[N-1])
