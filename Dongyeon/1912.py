import sys
n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
dp = [nums[0]]
ans = nums[0]
for i in range(1, len(nums)):
    dp.append(max(dp[i-1] + nums[i], nums[i]))
print(max(dp))
