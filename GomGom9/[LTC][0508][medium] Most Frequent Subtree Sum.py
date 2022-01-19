"""
    topics : Hash Table, Tree, Depth-First Search, Binary Tree
    link : https://leetcode.com/problems/most-frequent-subtree-sum/
    elapsed time : 25분
"""
import time
from typing import Optional, List, Counter

""" My solutions """
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def countNodeSum(self, node: Optional[TreeNode], counter: Counter) -> int:
        if not node:
            return 0
        current_node_sum = node.val + self.countNodeSum(node.left, counter) + self.countNodeSum(node.right, counter)
        counter[current_node_sum] = 1 if not counter[current_node_sum] else counter[current_node_sum] + 1
        return current_node_sum

    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        counter = Counter[int]()
        self.countNodeSum(root, counter)
        max_count = max(counter.values())
        return list(map(lambda x: x[0], filter(lambda x: x[1] == max_count, counter.items())))

""" Comments
- dfs로 현재 노드의 sum을 계산해서 count하는 방식으로 풀었어요. 
- 마지막에 counter, map, filter 문법이 생각이 안나서 오래 걸렸네요.. 파이썬과 더 친해져야 겠어요.
"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.findFrequentTreeSum(TreeNode(5, TreeNode(2), TreeNode(-3)))
case2 = solution.findFrequentTreeSum(TreeNode(5, TreeNode(2), TreeNode(-5)))
# case3 = solution.maxProfit([3, 3, 5], 8)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
