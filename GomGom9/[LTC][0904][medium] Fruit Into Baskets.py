"""
    topics : Array, Hash Table, Sliding Window
    link : https://leetcode.com/problems/fruit-into-baskets/
    elapsed time : 17분
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        result = 0
        basket_a_fruit = -1
        basket_a_count = 0
        basket_b_fruit = -1
        basket_b_count = 0
        last_fruit = -1
        last_continuous_count = 0
        for fruit in fruits:
            if basket_a_fruit == -1:
                basket_a_fruit = fruit
                basket_a_count += 1
            elif basket_a_fruit == fruit:
                basket_a_count += 1
            elif basket_b_fruit == -1:
                basket_b_fruit = fruit
                basket_b_count += 1
            elif basket_b_fruit == fruit:
                basket_b_count += 1
            else:
                result = max(result, basket_a_count + basket_b_count)
                basket_a_fruit = last_fruit
                basket_a_count = last_continuous_count
                basket_b_fruit = fruit
                basket_b_count = 1
            if last_fruit == fruit:
                last_continuous_count += 1
            else:
                last_fruit = fruit
                last_continuous_count = 1
        result = max(result, basket_a_count + basket_b_count)
        return result

""" Comments
문제를 봤을 때 best일 경우 O(n)이 겠다는 생각이 들어서, 순차적으로 반복하며 답을 찾을 수 있는 방법을 고민해서 접근함
"""

""" Other solutions """
# https://leetcode.com/problems/fruit-into-baskets/discuss/484921/Python-Solution-O(n)
# -> 풀이 자체는 유사하지만 dict를 이용해서 좀 더 적은 코드로 푼 풀이
""" Test cases """
solution = Solution()
start_time = time.process_time()

# case1 = solution.totalFruit(
#     [1, 0, 1, 4, 1, 4, 1, 2, 3])
case2 = solution.totalFruit([0,1,2,2])
case3 = solution.totalFruit([1,0,3,4,3])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
# print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
