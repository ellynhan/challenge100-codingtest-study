"""
문제:
    Given n non-negative integers representing an elevation map
    where the width of each bar is 1, compute how much water it can trap after raining.

제한:
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
입력:
    -
출력:
    -
시작:
    9.15 23:50
소요시간:
    1시간 30
"""
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_left, max_right = height[left], height[right]
        sum_h = 0

        while left < right:
            max_left, max_right = max(height[left], max_left), max(height[right], max_right)

            # 왼쪽 포인터를 큰쪽으로 이동
            if max_left <= max_right:
                sum_h += max_left - height[left]
                left += 1
            else:
                sum_h += max_right - height[right]
                right -= 1
        return sum_h