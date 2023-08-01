import sys

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        ans_l = []

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    ans_l.append(i)
                    ans_l.append(j)

        return ans_l
                
        
        
sol = Solution()
print(sol.twoSum(nums = [2,7,11,15], target = 9))