"""
    topics : Array, Two pointers
    link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    elapsed time : 14min
"""
import time
from collections import deque
from typing import Optional, List

""" My solutions """
class FirstSolution:
    def removeDuplicates(self, nums: List[int]) -> int:
        result = list(set(nums))
        nums.clear()
        nums.extend(result)
        nums.sort()
        return len(result)

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        prev = -101
        remove_target_indices = []
        for i, v in enumerate(nums):
            if v != prev:
                prev = v
            else:
                remove_target_indices.append(i)
        for i in reversed(remove_target_indices):
            nums.pop(i)
        return len(nums)

""" Comments """
# 1. 파이썬에서 call by reference를 고민해본적이 있었나..?
#   -> https://stackoverflow.com/questions/986006/how-do-i-pass-a-variable-by-reference
# 2. Two pointers 를 생각 조차 못했음 ㅎ

""" Other solutions """
# reference : https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/453327/python-3-100-less-memory-96-faster-only-len()-range()-called
#   -> Custom Judge 를 역이용해서 풀어버리네... 요구사항을 충족시키지 못하기에 참신하지만 올바른 접근은 아니라 생각함
class _Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = 0
        if len(nums) == 0: return length
        for i in range(1, len(nums)):
            if nums[length] < nums[i]:
                length += 1
                nums[length] = nums[i]
        return length + 1

# reference : https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/1591664/Simple-Python3-with-list-slices-O(n)
#   -> slice assignment 로 call by reference 를 해결한 접근
class _Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = sorted(set(nums))
        return len(nums)

""" Test cases """
solution = Solution()
start_time = time.process_time()

input1 = [1, 1, 2]
case1 = solution.removeDuplicates(input1)
input2 = [0, 1, 1, 1, 1, 2, 2, 3, 3, 4]
case2 = solution.removeDuplicates(input2)
# case3 = solution.removeDuplicates(ListNode(), ListNode(0))

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1} {input1}")
print(f"case2 : {case2} {input2}")
# print(f"case3 : {case3}")
print("-" * 30)
