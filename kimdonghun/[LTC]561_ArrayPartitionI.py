import sys

class Solution:
    def arrayPairSum(self, nums: list[int]) -> int:
        nums.sort()
        ans_l = []
        ans = 0

        for n in nums:
            ans_l.append(n)

            if(len(ans_l) == 2):
                ans += min(ans_l[0], ans_l[1])
                ans_l = []

        return ans

sol = Solution()
print(sol.arrayPairSum(nums = [6,2,6,5,1,2]))