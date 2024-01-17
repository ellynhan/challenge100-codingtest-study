class Solution:
    def combine(self, n, k):
        ans = []

        nums = [i for i in range(1, n + 1)]
        temp = []

        def backtracking(start):
            if len(temp) == k:
                ans.append(temp[:])
                return

            for i in range(start, len(nums)):
                if nums[i] not in temp:
                    temp.append(nums[i])
                    backtracking(i + 1)
                    temp.pop()

        backtracking(0)
        return ans
