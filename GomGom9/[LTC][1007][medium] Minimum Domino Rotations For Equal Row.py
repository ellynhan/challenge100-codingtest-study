"""
    topics : Array, Greedy
    link : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
    elapsed time : 15분
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        length = len(tops)
        top_only_counts = [0, 0, 0, 0, 0, 0, 0]
        bottom_only_counts = [0, 0, 0, 0, 0, 0, 0]
        both_counts = [0, 0, 0, 0, 0, 0, 0]
        for index in range(length):
            top_value = tops[index]
            bottom_value = bottoms[index]
            if top_value == bottom_value:
                both_counts[top_value] += 1
            else:
                top_only_counts[top_value] += 1
                bottom_only_counts[bottom_value] += 1

        min_rotations = [20001, 0, 0, 0, 0, 0, 0]
        for value in range(1, 7):
            both_count = both_counts[value]
            top_only_count = top_only_counts[value]
            bottom_only_count = bottom_only_counts[value]
            if top_only_count + bottom_only_count + both_count == length:
                min_rotations[value] = min(top_only_count, bottom_only_count)
            else:
                min_rotations[value] = 20001
        min_rotation = min(min_rotations)
        return min_rotation if min_rotation != 20001 else -1

""" Comments
각 도미노 숫자별로 각각 몇개씩 가지고 있는지를 조사해서 답을 구하는 접근
윗줄에만 있는 숫자별 갯수, 아랫줄에만 있는 숫자별 갯수, 두줄다 가지고 있는 숫자별갯수를 구했고, 각 숫자별로 세개의 합이 length와 일치하는 경우 정답이 되는
 것이고 아닌 경우 정답을 만들 수 없는 것이다. 이 중 윗줄만 가지고 있는 갯수와 아랫줄만 가지고 있는 갯수중 min값이 필요한 rotation이 된다.
"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.minDominoRotations(tops=[2, 1, 2, 4, 2, 2], bottoms=[5, 2, 6, 2, 3, 2])
case2 = solution.minDominoRotations(tops=[3, 5, 1, 2, 3], bottoms=[3, 6, 3, 3, 4])
# case3 = solution.minDominoRotations(])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
