"""
문제:
    Given a string s, return the longest palindromic substring in s.
제한:
    * 1 <= s.length <= 1000
    * s consist of only digits and English letters.
입력:
    -
출력:
    -
시작:
    9.15 12:40
소요시간:
    50분
"""
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 4:16
        if len(s) < 2 or s == s[::-1]:
            return s

        if len(s) == 2:
            if s != s[::-1]:
                return s[0]
        answer = s[0]

        for i in range(len(s)-1):
            if i+1 > len(s):
                return
            even = s[i:i+2]
            odd = s[i:i+3]

            if even == even[::-1]:
                if len(answer) < len(even):
                    answer = even
                left, right = i, i+2
                while left >= 0 and right <= len(s)-1:
                    left -= 1
                    right += 1
                    temp_even = s[left:right]
                    if temp_even == temp_even[::-1]:
                        even = temp_even
                        if len(answer) < len(even):
                            answer = even
                    else:
                        break

            if odd == odd[::-1]:
                if len(answer) < len(odd):
                    answer = odd
                left, right = i, i + 3
                while left >= 0 and right <= len(s)-1:
                    left -= 1
                    right += 1
                    temp_odd = s[left:right]
                    if temp_odd == temp_odd[::-1]:
                        odd = temp_odd
                        if len(answer) < len(odd):
                            answer = odd
                    else:
                        break
        return answer