# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        cur = root
        left, right = p, q

        if p.val > q.val:
            left = q
            right = p

        while cur:

            if cur.val > right.val:
                cur = cur.left
            elif left.val > cur.val:
                cur = cur.right
            else:
                return cur
