"""
    topics : Array, Hash Table, Divde and Conquer, Sorting, Counting
    link : https://leetcode.com/problems/majority-element/
    elapsed time : 2분
"""
import time
from collections import Counter
from operator import itemgetter
from typing import Optional, List, Dict

""" My solutions """
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return max(Counter(nums).items(), key=lambda x: x[1])[0]

""" Comments

"""

""" Other solutions """
# https://leetcode.com/problems/majority-element/discuss/51613/O(n)-time-O(1)-space-fastest-solution
# -> 굳!
""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.majorityElement([3, 2, 3])
case2 = solution.majorityElement([2, 2, 1, 1, 1, 2, 2])
# case3 = solution.reverseList()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
