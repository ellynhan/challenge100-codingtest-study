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
    9.2 21:20
소요시간:
    9분
"""

class Solution:
    def isPalindrome(self, sentence: str) -> bool:
        stack = list()
        for s in sentence:
            if s.isalnum():
                stack.append(s.lower())

        palindrome = list()

        for i in range(len(stack)-1, 0, -1):
            palindrome.append(stack[i])

        for i in range(len(stack)-1):
            if palindrome[i] != stack[i]:
                return False
        return True
