"""
    topics : Math, String, Simulation
    link : https://leetcode.com/problems/fizz-buzz/
    elapsed time : 측정 못함
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        for i in range(1, n + 1):
            if i % 15 == 0:
                result.append("FizzBuzz")
            elif i % 3 == 0:
                result.append("Fizz")
            elif i % 5 == 0:
                result.append("Buzz")
            else:
                result.append(str(i))
        return result

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.fizzBuzz(3)
case2 = solution.fizzBuzz(5)
case3 = solution.fizzBuzz(15)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
