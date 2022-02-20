"""
문제:
    Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ...,
    (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

제한:
    1 <= n <= 104
    nums.length == 2 * n
    -104 <= nums[i] <= 104
입력:
    -
출력:
    -
시작:
    9.15 03:05
소요시간:
    5분
"""

from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])

