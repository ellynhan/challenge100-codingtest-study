class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(numbers, path):
            prev_numbers = path.copy()
            if len(path) == len(nums):
                result.append(path)
                return
            for i in numbers:
                next_numbers = numbers.copy()
                next_numbers.remove(i)
                path.append(i)
                dfs(next_numbers, path)
                path = prev_numbers.copy()

        result = []

        dfs(nums, [])

        return result
