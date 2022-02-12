"""
    topics : Hash Table, String, Sorting
    link : https://leetcode.com/problems/valid-anagram/
    elapsed time : 1분
"""
import time
from collections import Counter
from operator import itemgetter
from typing import Optional, List, Dict

""" My solutions """
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.isAnagram(s = "anagram", t = "nagaram")
case2 = solution.isAnagram(s = "rat", t = "car")
# case3 = solution.reverseList()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
