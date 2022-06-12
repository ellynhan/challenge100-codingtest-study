# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def check_together(p, q):
            if p == None and q == None:
                return True
            elif p and q and p.val == q.val:
                return check_together(p.left, q.left) and check_together(p.right, q.right)
            return False
    
        return check_together(p, q)
