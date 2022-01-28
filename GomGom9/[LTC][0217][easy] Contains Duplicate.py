"""
    topics : Array, Hasy Table, Sorting
    link : https://leetcode.com/problems/contains-duplicate/
    elapsed time : 2분 20초
"""
import time
from collections import Counter
from typing import Optional, List, Dict

""" My solutions """
class Solution2:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_counter = Counter(nums)
        return max(num_counter.values()) >= 2

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        cache_set = set()
        for num in nums:
            if num in cache_set:
                return True
            cache_set.add(num)
        return False


""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.containsDuplicate([1,2,3,1])
case2 = solution.containsDuplicate([1,2,3,4])
case3 = solution.containsDuplicate([1,1,1,3,3,4,3,2,4,2])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
