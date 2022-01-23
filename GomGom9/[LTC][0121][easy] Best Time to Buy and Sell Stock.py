"""
    topics : Array, Dynamic Programming
    link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    elapsed time : xx
"""
import time
from typing import Optional, List
from collections import Counter, deque

""" My solutions """

""" Comments 
- 30분 내에 풀이에 실패함
    -> 문제의 조건을 제대로 파악하지 못했다는게 가장 큰 요인인거 같다. 
        조건을 잘못 생각하니 더 어렵게 문제를 풀게 됬고, 답은 찾았으나 time out이 발생했다. 
        최적화를 더 해봤지만, 애초에 O(n) 문제를 O(nlogn) 정도로 최적화 한들 의미가 없었음.
    -> 풀이 중 문제점을 직면했을 때, 더 어렵게만 접근하는 거 같다. 초기의 내 생각이 틀렸을 가능성을 배제하지 말자.
- 까먹을 떄쯤 다시 풀기.

"""

""" Other solutions """
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/884314/Python-3-greater-Very-simple-solution.-Explanation-added
# 문제 자체가 순차적으로 접근하므로 앞선 최소값은 뒤에서 다른 최소값을 찾기까지 계속 최소값이다.
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        maxProfit = 0
        minPurchase = prices[0]
        for i in range(1, len(prices)):
            maxProfit = max(maxProfit, prices[i] - minPurchase)
            minPurchase = min(minPurchase, prices[i])
        return maxProfit
""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.maxProfit([7,6,4,3,1])
case2 = solution.maxProfit([7,1,5,3,6,4])
# case3 = solution.maxProfit()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
