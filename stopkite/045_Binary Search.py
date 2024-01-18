class Solution:
    def search(self, nums, target):
        def backtracking(l, r):
            if l > r:
                return -1

            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                return backtracking(l, mid - 1)
            else:
                return backtracking(mid + 1, r)

        return backtracking(0, len(nums) - 1)


solution = Solution()
print(solution.search([-1, 0, 3, 5, 9, 12], 9))
