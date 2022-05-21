"""
    topics : Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
    link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
    elapsed time : 10min
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
    def bstRecursion(self, nums: List[int], start_index: int, end_index: int, node: Optional[TreeNode]):
        center_index = (start_index + end_index) // 2
        node.val = nums[center_index]

        next_left_end_index = center_index - 1
        if next_left_end_index >= start_index:
            node.left = left_node = TreeNode()
            self.bstRecursion(nums, start_index, next_left_end_index, left_node)

        next_right_start_index = center_index + 1
        if next_right_start_index <= end_index:
            node.right = right_node = TreeNode()
            self.bstRecursion(nums, next_right_start_index, end_index, right_node)


    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        root_node = TreeNode()
        self.bstRecursion(nums, 0, len(nums) - 1, root_node)
        return root_node



""" Comments """

""" Other solutions """
# https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/570178/Python3-Recursive-and-Iterative-Solution-(one-stack)-With-Detailed-Explanations.
# -> 나는 recursive를 더 선호 하는 것 같음.
#     -> recursive와 iterative의 장단점을 고려해서 선택을 좀 더 고민해보면 좋을듯.
def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    if not nums: return None

    # Each item in the stack holds: floor, ceiling, parent and parent's direction.
    stack = [(0, len(nums) - 1, None, None)]
    root = None
    while stack:
        floor, ceiling, parent, direction = stack.pop()
        middleIndex = (floor + ceiling) // 2
        n = TreeNode(nums[middleIndex])

        # Add the root node. parent should only ever be null in this one case.
        if not parent:
            root = n
        else:
            if direction == 'l':
                parent.left = n
            elif direction == 'r':
                parent.right = n

        # Add the next items to the stack, as necessary. Add right first.
        # Similar to the recursive approach, both floor and ceiling should never cross.
        if middleIndex + 1 <= ceiling:
            stack.append((middleIndex + 1, ceiling, n, 'r'))
        if floor <= middleIndex - 1:
            stack.append((floor, middleIndex - 1, n, 'l'))
    return root
""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.sortedArrayToBST([-10,-3,0,5,9])
# case2 = solution.isSymmetric(None)
case3 = solution.sortedArrayToBST([1,3])

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
