"""
문제:
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.
제한:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
입력:
    -
출력:
    -
시작:
    9.15 03:21
소요시간:
    30분
"""

from typing import List

#03:21
def productExceptSelf(nums: List[int]) -> List[int]:
    left_answer = []
    answer = []

    sub_p = 1

    for num in nums:
        left_answer.append(sub_p)
        sub_p *= num

    nums.reverse()

    right_answer = []
    sub_p = 1

    for i, num in enumerate(nums):
        right_answer.append(sub_p)
        sub_p *= num

    right_answer.reverse()

    for i in range(len(nums)):
        answer.append(left_answer[i]*right_answer[i])
    return answer