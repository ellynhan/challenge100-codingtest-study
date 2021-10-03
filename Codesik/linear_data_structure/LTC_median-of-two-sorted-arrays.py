"""
문제:
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).

제한:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106

입력:
    -
출력:
    -
시작:
    9.19 18:15
소요시간:
    5분
"""

from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = (nums1+nums2)
        nums.sort()
        if len(nums) % 2 == 0:
            return float((nums[int(len(nums)/2)] + nums[int(len(nums)/2)-1]) / 2)
        else:
            return float(nums[int(len(nums)/2)])