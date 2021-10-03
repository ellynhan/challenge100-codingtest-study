"""
문제:
    Given an integer x, return true if x is palindrome integer.
    An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

제한:
    -231 <= x <= 231 - 1
입력:
    -
출력:
    -
시작:
    9.19 21:35
소요시간:
    1분
"""
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]