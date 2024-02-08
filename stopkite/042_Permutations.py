class Solution:
    def permute(self, nums):
        ans = []
        temp = []
        depth = len(nums)

        def backtracking():
            if len(temp) == depth:
                ans.append(temp[:])
                return

            for i in range(len(nums)):
                if nums[i] not in temp:
                    temp.append(nums[i])
                    backtracking()
                    temp.pop()

        backtracking()

        return ans