"""
    topics : Tree, Depth-First Search, Breadth-First Search, Binary Tree
    link : https://leetcode.com/problems/symmetric-tree/
    elapsed time : 8min
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
    def isMirror(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if left is None and right is None:
            return True
        if (left is None and right is not None) or (left is not None and right is None) or left.val != right.val:
            return False
        if left.val == right.val and left.left is None and left.right is None and right.left is None and right.right is None:
            return True
        return self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isMirror(root.left, root.right)

""" Comments """

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.isSymmetric(TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(2, TreeNode(4), TreeNode(3))))
# case2 = solution.isSymmetric(None)
case3 = solution.isSymmetric(TreeNode(1, TreeNode(2, None, TreeNode(3)), TreeNode(2, None, TreeNode(3))))

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
