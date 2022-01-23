"""
    topics : Math, Dynamic Programming, Memoization
    link : https://leetcode.com/problems/climbing-stairs/
    elapsed time : 12min
"""
import time
from collections import deque
from functools import reduce
from itertools import combinations
from math import factorial
from typing import Optional, List

""" My solutions """
class FirstSolution:
    def climbStairs(self, n: int) -> int:
        max_two_count = n // 2
        result = 0
        for two_count in range(max_two_count + 1):
            one_count = n - (two_count * 2)
            result += factorial(one_count + two_count) // factorial(two_count) // factorial(one_count)
        return result

class Solution:
    def ncr(self, n: int, r: int) -> int:
        return reduce((lambda x, y: x * y), range(n, n - r, -1), 1) // reduce((lambda x, y: x * y), range(1, r + 1), 1)

    def climbStairs(self, num: int) -> int:
        max_two_count = num // 2
        result = 0
        for two_count in range(max_two_count + 1):
            one_count = num - (two_count * 2)
            n = one_count + two_count
            r = min(one_count, two_count)
            result += reduce((lambda x, y: x * y), range(n, n - r, -1), 1) // reduce((lambda x, y: x * y), range(1, r + 1), 1)
        return result

""" Comments """

""" Other solutions """
# reference : https://leetcode.com/problems/climbing-stairs/discuss/861147/Clean-Python-or-Fibonacci-Growth
#   -> x[i] = x[n-1] + x[n-2]
#   -> 이걸 왜 못 찾았지 ;;;;

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.climbStairs(2)
case2 = solution.climbStairs(45)
case3 = solution.climbStairs(3)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
