"""
    topics : Math, String, Simulation
    link : https://leetcode.com/problems/multiply-strings/
    elapsed time : (정확히 측정 못함) 10분 전후
"""
import time

""" My solutions """
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        return (self.strNumToInt(num1) * self.strNumToInt(num2)).__str__()

    def strNumToInt(self, num: str):
        str_to_digit_map = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}
        last_index = len(num) - 1
        result = 0
        for index, digit in enumerate(num):
            result += pow(10, last_index - index) * str_to_digit_map[digit]
        return result

""" Comments
- str로 주어진 숫자 str을 반복하며 현재 숫자 * index를 통한 10의 자리?로 int로 변환시켰어요. 이후에 조건에 int를 str로 컨버트하지 말라고는 없길레
- int 곱을 str로 변환해서 리턴했어요.
"""

""" Other solutions """
# - 풀이 자체는 거의 동일한데 파이썬 **로 제곱하는 것과 ord로 숫자 구하는건 한번 눈여겨 볼만한거 같아요.

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.multiply("2", "3")
case2 = solution.multiply("123", "456")
# case3 = solution.maxProfit([3, 3, 5], 8)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
