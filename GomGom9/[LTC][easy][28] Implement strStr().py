"""
    topics : String, Two pointers, String Matching
    link : https://leetcode.com/problems/implement-strstr/submissions/
    elapsed time : 3min
"""
import time
from collections import deque
from typing import Optional, List

""" My solutions """
class FirstSolution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        start = 0
        haystack_length = len(haystack)
        needle_length = len(needle)
        while start + needle_length <= haystack_length:
            if haystack[start:start + needle_length] == needle:
                return start
            start += 1
        return -1

""" Comments """
# discussion에 다른 풀이로 rabin-karp 나 KMP가 있었고 O(n+m)으로 소개하지만, worst case는 O(nm)이 된다. 대부분의 언어에서 문자열 서치기능을 제공하기에
# 별도로 더 파볼 필요는 못 느꼈지만, 어찌됬든 KMP의 접근법은 다른 풀이에 응용 가능할 듯

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.strStr("hello", "ll")
case2 = solution.strStr("aaaaa", "bba")
case3 = solution.strStr("", "")

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
