# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        # print(root)

        num = 1

        if not root:
            return 0
        
        num += max(self.maxDepth(root.right), self.maxDepth(root.left))

        return num