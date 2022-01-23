import sys

class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        ans_l = []

        mul = 1
        for i in range(0, len(nums)):
            ans_l.append(mul)
            mul *= nums[i]

        mul = 1
        for i in range(len(nums) - 1, 0 - 1, -1):
            ans_l[i] *= mul
            mul *= nums[i]

        return ans_l

sol = Solution()
print(sol.productExceptSelf(nums = [-1,1,0,-3,3]))