"""
    topics : Array, Hash Table
    link : https://leetcode.com/problems/two-sum/
    elapsed time : 10min
"""
import time
from typing import List

""" My solutions """
class FirstSolution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums) - 1, -1, -1):
            required_num = target - nums[i]
            if required_num in nums[:i]:
                return [i, nums.index(required_num)]
            else:
                continue

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in reversed(range(len(nums))):
            required_num = target - nums[i]
            try:
                required_num_index = nums.index(required_num)
                if i != required_num_index:
                    return [required_num_index, i]
            except ValueError:
                continue

""" Comments """
# 1. 파이썬 문법 기억이 안나...ㅠㅠ
# 2. python collection 기본 제공 함수들 겉 보기엔 비슷한 연산 임에도 성능 차이가 있었음
#   -> why? 상수배의 차이일까?


""" Other solutions """
# reference : https://leetcode.com/problems/two-sum/discuss/589804/Python3-easy-and-faster-than-97.93
#   -> 해쉬가 확실히 시간 면에서 좋음.
class _Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memory = {}
        for i, e in enumerate(nums):
            if e in memory: return (memory[e], i)
            memory[(target - e)] = i
        return []

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.twoSum([2, 7, 11, 15], 9)
case2 = solution.twoSum([3, 2, 4], 6)
case3 = solution.twoSum([3, 3], 6)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
