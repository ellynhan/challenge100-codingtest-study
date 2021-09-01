# class TreeNode: 해당 리트코드 문제 내 내장 class

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    @staticmethod
    def increasingBST(root: TreeNode) -> TreeNode:
        def dfs(start):
            visited = []
            stack = [start]
            while stack:
                node = stack.pop()
                if node.val not in visited:
                    if node.left is not None:
                        stack += [node.left]
                    if node.right is not None:
                        stack += [node.right]
                visited += [node.val]

            return visited

        existing_num = sorted(dfs(root))

        head = TreeNode(-1)
        cursor = head

        for entry in existing_num:
            cursor.right = TreeNode(entry)
            cursor = cursor.right

        return head.right
