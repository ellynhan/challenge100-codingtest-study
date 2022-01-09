"""
    topics : String
    link : https://leetcode.com/problems/longest-common-prefix/
    elapsed time : 9min
"""
import time
from typing import List

""" My solutions """
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs_size = len(strs)
        if strs_size == 0:
            return ''
        if strs_size == 1:
            return strs[0]

        result = ""
        for i in range(200):
            try:
                current_char = strs[0][i]
                for string in strs:
                    if string[i] != current_char:
                        return result
            except IndexError:
                return result
            result += current_char

""" Comments """

""" Other solutions """
# reference : https://leetcode.com/problems/longest-common-prefix/discuss/783976/Python-Simple-Solution-beats-100-runtime-12ms/1120887
#   -> 파이썬의 string 비교 방법(i.g. "aa" < "ab" == true)을 이용한 풀이로
#       unicode 기준 가장 낮은 str과 가장 높은 str의 공통 Prefix를 찾는 접근
class _Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:  # O(n + m) time
        i, a, z = 0, min(strs), max(strs)
        print(i, a, z)
        while i < min(len(a), len(z)) and a[i] == z[i]:
            i += 1
        return a[:i]

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.longestCommonPrefix(["flower","flow","flight"])
case2 = solution.longestCommonPrefix(["dog","racecar","car"])
case3 = solution.longestCommonPrefix(["dog"])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
