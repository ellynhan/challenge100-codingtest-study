import sys

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        max_profit = 0
        min_price = sys.maxsize

        for p in prices:
            min_price = min(p, min_price)
            max_profit = max(max_profit, p - min_price)
        
        return max_profit

sol = Solution()
print(sol.maxProfit(prices = [7,1,5,3,6,4]))