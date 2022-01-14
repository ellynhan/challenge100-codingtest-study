"""
    topics : Array, Divide and Conqure, Dynamic Programming
    link : https://leetcode.com/problems/maximum-subarray/
    elapsed time : 19min
"""
import time
from collections import deque
from typing import Optional, List

""" My solutions """
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max = -10001
        sum = 0
        nums_count = 0
        for num in nums:
            if num + sum > 0:
                sum += num
                nums_count += 1
            elif nums_count == 0:
                max = max if max >= num else num
                nums_count = 0
                continue
            else:
                sum = 0
                nums_count = 0
            max = max if max >= sum else sum
        return max



""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])
case2 = solution.maxSubArray([1])
case3 = solution.maxSubArray([5, 4, -1, 7, 8])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
