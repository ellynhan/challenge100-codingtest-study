# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def compare_tree(a, b):
            if a is None and b is None:
                return True
            # 둘 중 하나만 None이면  False
            if (a is None or b is None) or a.val != b.val:
                return False
            # left, right 둘 다 같을경우  True
            return compare_tree(a.left, b.left) and compare_tree(a.right, b.right)
            
        def dfs(node, subRoot):
            if compare_tree(node, subRoot):
                return True
            if node:
                return dfs(node.left, subRoot) or dfs(node.right, subRoot)
            # 둘 다 None인경우 True
            return node == subRoot
        
        return dfs(root, subRoot)
            