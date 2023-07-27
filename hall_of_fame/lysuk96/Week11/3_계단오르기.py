N = int(input())
nums = [int(input()) for _ in range(N)]
if N==1:
    print(nums[0])
else:
    dp = [[0]*N for _ in range(2)]
    dp[0][0] = nums[0]
    dp[0][1] = nums[1]
    dp[1][1] = nums[0]+nums[1]
    for i in range(2, N):
        dp[0][i] = max(dp[0][i-2], dp[1][i-2]) + nums[i]
        dp[1][i] = dp[0][i-1]+nums[i]
    print(max(dp[0][N-1],dp[1][N-1]))
