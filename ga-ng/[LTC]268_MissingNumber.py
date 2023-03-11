class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        size = len(nums)
        dp = [0] * (size+1)

        for i in nums:
            dp[i] = 1

        return dp.index(0)

