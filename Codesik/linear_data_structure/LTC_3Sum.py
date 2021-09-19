"""
문제:
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

제한:
    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105
입력:
    -
출력:
    -
시작:
    9.15 01:05
소요시간:
    45분
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = set()
        nums.sort()
        print(nums)
        for index, num in enumerate(nums):
            left = index + 1
            right = len(nums) - 1
            while left < right:
                sum = num + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                # 정답
                else:
                    answer.add((num, nums[left], nums[right]))
                    left += 1
                    right -= 1
        return answer
