class Solution:
    def subsets(self, nums):
        ans = []
        temp = []

        def backtracking(start, cnt):
            if len(temp) == cnt:
                ans.append(temp[:])
                return

            for i in range(start, len(nums)):
                if nums[i] not in temp:
                    temp.append(nums[i])
                    backtracking(i + 1, cnt)
                    temp.pop()

        for cnt in range(len(nums) + 1):
            backtracking(0, cnt)

        return ans
