"""
    topics : Stack, Design
    link : https://leetcode.com/problems/min-stack/
    elapsed time : 측정 못함
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class MinStack:
    def __init__(self):
        self.min = None
        self.previous_mins = []
        self.inner_stack = []

    def push(self, val: int) -> None:
        self.inner_stack.append(val)
        if self.min is None or val <= self.min:
            self.min = val
            self.previous_mins.append(val)

    def pop(self) -> None:
        top = self.inner_stack.pop()
        if top == self.min:
            self.previous_mins.pop()
            self.min = self.previous_mins[-1] if self.previous_mins else None

    def top(self) -> int:
        return self.inner_stack[-1]

    def getMin(self) -> int:
        return self.min

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = MinStack()
solution.push(0)
solution.push(1)
solution.push(0)
solution.getMin()
solution.pop()
solution.getMin()
start_time = time.process_time()

# case1 = solution.findBottomLeftValue()
# case2 = solution.findBottomLeftValue()
# case3 = solution.maxProfit()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
# print(f"case1 : {case1}")
# print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
