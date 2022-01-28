"""
    topics : Tree, Depth-First Search, Breadth-First Search, Binary Tree
    link : https://leetcode.com/problems/find-bottom-left-tree-value/
    elapsed time : 6분 50초
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.depth_leftmost_dict = {}

    def innerFunction(self, node: Optional[TreeNode], depth: int):
        if not node:
            return
        self.depth_leftmost_dict[depth] = node.val
        self.innerFunction(node.right, depth + 1)
        self.innerFunction(node.left, depth + 1)

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.innerFunction(root, 1)
        return self.depth_leftmost_dict[max(self.depth_leftmost_dict)]

""" Comments
가장 depth가 깊은 곳의 가장 왼쪽 value를 찾아야 해서, 오른쪽 먼저 탐색하면서 depth의 value를 덮어 씌우고 탐색이 끝난 후 가장 깊은 depth의 value를
답으로 리턴했어요.
"""

""" Other solutions """
# 유의미한 차이가 있는 접근은 없었고, 일부 상수배 시간을 아끼는 방법은 있었어요. 가령 dict로 전부 관리하지 않고 최대 depth와 value만 관리하며 왼쪽 우선 탐색하기

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.findBottomLeftValue(TreeNode(2, TreeNode(1), TreeNode(3)))
case2 = solution.findBottomLeftValue(
    TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3, TreeNode(5, TreeNode(7)), TreeNode(6))))
# case3 = solution.maxProfit([3, 3, 5], 8)

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
