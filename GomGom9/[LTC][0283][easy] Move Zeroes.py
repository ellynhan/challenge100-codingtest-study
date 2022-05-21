"""
    topics : Array, Two Pointers
    link : https://leetcode.com/problems/move-zeroes/
    elapsed time : 7분
"""
import time
from typing import Optional, List, Dict

""" My solutions """
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i, j, size = 0, 0, len(nums)
        while j < size:
            num_j = nums[j]
            if num_j == 0:
                j += 1
                continue
            nums[i] = num_j
            i += 1
            j += 1
        while i < size:
            nums[i] = 0
            i += 1

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

a = [0, 1, 0, 3, 12]
case1 = solution.moveZeroes(a)
print(a)
case2 = solution.moveZeroes([0])
# case3 = solution.reverseList()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
