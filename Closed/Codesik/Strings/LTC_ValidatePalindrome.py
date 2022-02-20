"""
문제:
    Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
제한:
    * 1 <= s.length <= 2 * 105
    * s consists only of printable ASCII characters.
입력:
    -
출력:
    -
시작:
    9.12 21:20
소요시간:
    9분
"""
import re

class Solution:
    def isPalindrome(self, sentence: str) -> bool:
        sentence = sentence.lower()
        sentence = re.sub('[^a-z0-9]', '', sentence)

        return sentence == sentence[::-1]
