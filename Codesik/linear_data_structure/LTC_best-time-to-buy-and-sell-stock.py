"""
문제:
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

제한:
    1 <= prices.length <= 105
    0 <= prices[i] <= 104
입력:
    -
출력:
    -
시작:
    9.19 10:50
소요시간:
    20분
"""

import sys
from typing import List


def maxProfit(prices: List[int]) -> int:
    min_value = sys.maxsize
    answer = 0

    for price in prices:
        min_value = min(price, min_value)
        answer = max(answer, price - min_value)
    return answer


print(maxProfit([7,1,5,3,6,4]))