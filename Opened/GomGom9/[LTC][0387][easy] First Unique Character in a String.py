"""
    topics : Hash Table, String, Queue, Counting
    link : https://leetcode.com/problems/first-unique-character-in-a-string/
    elapsed time : 7분
"""
import time
from collections import Counter
from typing import Optional, List, Dict

""" My solutions """
class Solution:
    def firstUniqChar(self, s: str) -> int:
        character_counter = Counter(s)
        unique_characters = dict(filter(lambda x: x[1] == 1, character_counter.items()))
        for index, character in enumerate(s):
            if character in unique_characters:
                return index
        return -1

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.firstUniqChar("leetcode")
case2 = solution.firstUniqChar("loveleetcode")
case3 = solution.firstUniqChar("aabb")

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
