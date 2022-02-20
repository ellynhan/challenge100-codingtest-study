"""
문제:
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

제한:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
입력:
    -
출력:
    -
시작:
    9.15 01:50
소요시간:
    15분
"""
from typing import List

# O(N^2)이하로 만들어보자.
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, num in enumerate(nums):
            dict[num] = i

        for i, num in enumerate(nums):
            if target-num in dict and i != dict[target-num]:
                return [i, dict[target-num]]