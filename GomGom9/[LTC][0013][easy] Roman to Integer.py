"""
    topics : Math, Hash Table, String
    link : https://leetcode.com/problems/roman-to-integer/
    elapsed time : 12min
"""
import time

""" My solutions """
class Solution:
    def romanToInt(self, s: str) -> int:
        symbol_value_dict = {"M": 1000, "CM": 900, "D": 500, "CD": 400, "C": 100, "XC": 90, "L": 50, "XL": 40, "X": 10,
                             "IX": 9, "V": 5, "IV": 4, "I": 1}
        result = 0
        for symbol, value in symbol_value_dict.items():
            while s.startswith(symbol):
                result += value
                s = s.removeprefix(symbol)
        return result

""" Comments """
# 난이도 대비 시간이 오래 걸림
#   -> 문제 읽는 시간과 어색한 파이썬 문법이 주된 이유 같음
#       -> 당분간 easy 문제 많이 풀기.

""" Other solutions """
# reference : https://leetcode.com/problems/roman-to-integer/discuss/264743/Clean-Python-beats-99.78.
#   -> wow
class _Solution:
    def romanToInt(self, s: str) -> int:
        translations = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        number = 0
        s = s.replace("IV", "IIII").replace("IX", "VIIII")
        s = s.replace("XL", "XXXX").replace("XC", "LXXXX")
        s = s.replace("CD", "CCCC").replace("CM", "DCCCC")
        for char in s:
            number += translations[char]
        return number

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.romanToInt("III")
case2 = solution.romanToInt("LVIII")
case3 = solution.romanToInt("MCMXCIV")

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
