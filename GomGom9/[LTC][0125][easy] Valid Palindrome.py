"""
    topics : Two Pointers, String
    link : https://leetcode.com/problems/valid-palindrome/
    elapsed time : 측정 못함
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class Solution:
    def isPalindrome(self, s: str) -> bool:
        def toAlphanumeric(string: str) -> List[str]:
            result = []
            for char in string:
                if "a" <= char <= "z" or "0" <= char <= "9":
                    result.append(char)
                elif "A" <= char <= "Z":
                    result.append(chr(ord(char) + 32))
            return result

        alphanumeric_s_list = toAlphanumeric(s)
        size = len(alphanumeric_s_list)
        mid = size // 2
        if size == 0:
            return True
        front_last = mid
        end_stat = mid if size % 2 == 0 else mid + 1
        a = alphanumeric_s_list[:front_last]
        b = alphanumeric_s_list[end_stat:]
        b.reverse()
        return a == b

""" Comments

"""

""" Other solutions """
# https://leetcode.com/problems/valid-palindrome/discuss/1151720/Python3-O(n)-time-O(1)-space.-Well-explained
# 앞, 뒤 인덱스를 관리하며 바로 답을 찾아서 풀이의 평균 기대 효율이 더 좋음
# isdigit(), isalnum(), isalpha() 함수 유용할 듯!
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # i starts at beginning of s and j starts at the end
        i, j = 0, len(s) - 1
        # While i is still before j
        while i < j:
            # If i is not an alpha-numeric character then advance i
            if not s[i].isalnum():
                i += 1
            # If j is not an alpha-numeric character then advance i
            elif not s[j].isalnum():
                j -= 1
            # Both i and j are alpha-numeric characters at this point so if they do not match return the fact that input was non-palendromic
            elif s[i].lower() != s[j].lower():
                return False
            # Otherwise characters matched and we should look at the next pair of characters
            else:
                i, j = i + 1, j - 1
        # The entire stirng was verified and we return the fact that the input string was palendromic
        return True
""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.isPalindrome("A man, a plan, a canal: Panama")
case2 = solution.isPalindrome("race a car")
case3 = solution.isPalindrome(" ")

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
