"""
    topics : Array, Dynamic Programming
    link : https://leetcode.com/problems/pascals-triangle/
    elapsed time : 6min
"""
import time
from typing import Optional, List

""" My solutions """
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal_triangle = [[1]]
        for row_num in range(2, numRows + 1):
            row_list = []
            for i in range(row_num):
                previous_list = pascal_triangle[row_num - 2]
                current_value = previous_list[i - 1] + previous_list[i] if 0 < i < row_num - 1 else 1
                row_list.append(current_value)
            pascal_triangle.append(row_list)
        return pascal_triangle

""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.generate(5)
# case2 = solution.isSymmetric(None)
case3 = solution.generate(1)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
