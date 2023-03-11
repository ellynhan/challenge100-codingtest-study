# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (not p and q)or(p and not q):
            return False
        elif not p and not q:
            return True

        if p.val != q.val:
            return False

        if self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right):
            return True

        else:
            return False