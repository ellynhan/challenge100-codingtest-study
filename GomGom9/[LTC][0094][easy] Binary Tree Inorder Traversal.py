"""
    topics : Stack, Tree, Depth-First Search, Binary Tree
    link : https://leetcode.com/problems/binary-tree-inorder-traversal/
    elapsed time : 6min
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
    def inOrder(self, node: Optional[TreeNode], result: List[int]):
        if node is None:
            return
        self.inOrder(node.left, result)
        result.append(node.val)
        self.inOrder(node.right, result)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.inOrder(root, result)
        return result

""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.inorderTraversal(TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7))))
# case2 = solution.isSymmetric(None)
case3 = solution.inorderTraversal(TreeNode(1, None, TreeNode(2)))

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
