"""
    topics : String, Stack
    link : https://leetcode.com/problems/valid-parentheses/
    elapsed time : 12min
"""
import time

""" My solutions """
class Solution:
    def isValid(self, s: str) -> bool:
        closer_opener_map = {")": "(", "}": "{", "]": "["}
        opener_stack = []
        for bracket in s:
            if bracket not in closer_opener_map:
                opener_stack.append(bracket)
            elif not opener_stack or closer_opener_map[bracket] != opener_stack[-1]:
                return False
            else:
                opener_stack.pop()
        return False if opener_stack else True

""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.isValid("()")
case2 = solution.isValid("()[]{}")
case3 = solution.isValid("{[]}")

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
