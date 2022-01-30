"""
    topics : Array, Binary Search, Sorting
    link : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
    elapsed time : 8분
"""
import time
from collections import Counter
from typing import Optional, List, Dict

""" My solutions """
class Solution1:
    def specialArray(self, nums: List[int]) -> int:
        num_counter = Counter(nums)
        result = -1
        for x in range(0, len(nums) + 1):
            value = sum(map(lambda y: y[1], filter(lambda y: y[0] >= x, num_counter.items())))
            if x == value:
                if result == -1:
                    result = value
                else:
                    return -1
        return result

class Solution:
    def specialArray(self, nums: List[int]) -> int:
        num_counter = Counter(nums)
        result = -1

        def countMoreThan(y: int) -> int:
            total_count = 0
            for num, count in num_counter.items():
                if num >= y:
                    total_count += count
            return total_count

        for x in range(0, len(nums) + 1):
            value = countMoreThan(x)
            if x == value:
                if result == -1:
                    result = value
                else:
                    return -1
        return result
""" Comments
문제가 심플해서 nlogn의 sort를 피하려고 counter를 이용해 접근했는데, 중복되는 숫자가 많은 경우에는 n에 수렴하겠지만 중복된 숫자가 없을 경우 n^2에
수렴해서 오히려 효율성이 떨어졌다. 
"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.specialArray([3, 5])
case2 = solution.specialArray([0, 0])
case3 = solution.specialArray([0, 4, 3, 0, 4])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
