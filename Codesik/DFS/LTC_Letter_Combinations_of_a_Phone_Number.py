"""
문제:
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
    Return the answer in any order.
    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

제한:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
입력:
    -
출력:
    -
시작:
    9.19 19:40
소요시간:
    10분
"""

from typing import List
from itertools import product


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []

        phone = dict()
        phone['2'] = ['a', 'b', 'c']
        phone['3'] = ['d', 'e', 'f']
        phone['4'] = ['g', 'h', 'i']
        phone['5'] = ['j', 'k', 'l']
        phone['6'] = ['m', 'n', 'o']
        phone['7'] = ['p', 'q', 'r', 's']
        phone['8'] = ['t', 'u', 'v']
        phone['9'] = ['w', 'x', 'y', 'z']

        have_to_product = []

        for digit in digits:
            have_to_product.append(phone[str(digit)])

        product_list = list(product(*have_to_product))
        answer = []
        for el in product_list:
            answer.append("".join(el))

        return answer