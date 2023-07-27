
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        left = 0
        right = len(nums) - 1
        stnums = sorted(nums)

        while left != right:

            sumVal = stnums[left] + stnums[right]
            # print(sumVal)            
            if sumVal > target:
                right -= 1
            elif sumVal < target:
                left += 1
            else:
                break


        left_index = nums.index(stnums[left])
        nums[left_index] = -10**10
        right_index = nums.index(stnums[right])

        return [left_index, right_index]