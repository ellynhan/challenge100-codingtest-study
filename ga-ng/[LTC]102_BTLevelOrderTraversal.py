# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        ans = []
        if not root:
            return ans

        cklevel = 0
        level = 0

        st = [[root, level]]
        temp = []
        while st:
            tempRoot, templevel = st[0]
            del st[0]

            if cklevel == templevel:
                temp.append(tempRoot.val)
            else:
                ans.append(temp)
                cklevel += 1
                temp = [tempRoot.val]

            level = templevel + 1
            if tempRoot.left:
                st.append([tempRoot.left, level])
            if tempRoot.right:
                st.append([tempRoot.right, level])

        if temp:
            ans.append(temp)

        return ans