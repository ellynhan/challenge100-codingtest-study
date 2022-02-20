"""
문제:
    Write a function that reverses a string. The input string is given as an array of characters s.
제한:
    * 1 <= s.length <= 105
    * s[i] is a printable ascii character.
입력:
    -
출력:
    -
시작:
    9.13 02:23
소요시간:
    1분
"""
from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        # We can solve this problem, like this
        # But We use Two Pointer
        # s.reverse()

        l, r = 0, len(s) - 1

        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1