"""
    topics : Array, Two Pointers, Sorting
    link : https://leetcode.com/problems/merge-sorted-array/
    elapsed time : 2min
"""
import time
from collections import deque
from functools import reduce
from itertools import combinations
from math import factorial
from typing import Optional, List

""" My solutions """
class FirstSolution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        nums1[m:] = nums2
        nums1.sort()

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i, j, k = m-1, n-1, m + n - 1
        while k >= 0:
            num1 = nums1[i] if i >= 0 else - 2100000000
            num2 = nums2[j] if j >= 0 else - 2100000000
            if num1 > num2:
                nums1[k] = num1
                i -= 1
            else:
                nums1[k] = num2
                j -= 1
            k -= 1


""" Comments """

""" Other solutions """


""" Test cases """
solution = Solution()
start_time = time.process_time()


case1 = solution.merge([-10,-10,-9,-9,-9,-8,-8,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-3,-3,-2,-2,-1,-1,0,1,1,1,2,2,2,3,3,3,4,5,5,6,6,6,6,7,7,7,7,8,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
,55,
[-10,-10,-9,-9,-9,-9,-8,-8,-8,-8,-8,-7,-7,-7,-7,-7,-7,-7,-7,-6,-6,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-4,-4,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,9,9,9,9],
99)
case2 = solution.merge(nums1 = [1], m = 1, nums2 = [], n = 0)
case3 = solution.merge(nums1 = [0], m = 0, nums2 = [1], n = 1)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
