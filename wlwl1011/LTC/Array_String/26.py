class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        insetIndex = 1
        for i in range(1, len(nums)):
            if nums[i-1] != nums[i]:
                nums[insetIndex] = nums[i]
                insetIndex += 1
        return insetIndex          
        