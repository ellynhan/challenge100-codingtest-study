"""
    topics : Tree, Depth-First Search, Breadth-First Search, Binary Tree
    link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
    elapsed time : 7min
"""
import time
from typing import Optional, List

""" My solutions """
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def calCulDepth(self, node: Optional[TreeNode], depth: int) -> int:
        if node is None:
            return depth
        return max(self.calCulDepth(node.left, depth + 1), self.calCulDepth(node.right, depth + 1))

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.calCulDepth(root, 0)


""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.maxDepth(TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7))))
# case2 = solution.isSymmetric(None)
case3 = solution.maxDepth(TreeNode(1, None, TreeNode(2)))

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
