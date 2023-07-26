# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        if not root:
            return False
        if not subRoot:
            return True


        if self.findSub(root, subRoot):
            return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def findSub(self, r, s):
        if not r and not s:
            return True

        if r and s and r.val == s.val:
            return self.findSub(r.left, s.left) and self.findSub(r.right, s.right)

        return False