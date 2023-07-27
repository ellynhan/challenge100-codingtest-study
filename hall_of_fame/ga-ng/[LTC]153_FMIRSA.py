class Solution:
    def findMin(self, nums: List[int]) -> int:
        # print(nums)

        length = len(nums)
        left, right = 0, length-1
        mid = length//2
        ans = 5001

        if length == 1:
            return nums[left]
        elif length == 2:
            return min(nums[left], nums[right])

        while left < right:

            ans = min(ans, nums[left], nums[right], nums[mid])

            if mid == left or mid == right or left == right:
                break
                
            if nums[mid] > nums[right]:
                left = mid + 1
                mid = (right + left)//2
            else:
                right = mid - 1
                mid = (right + left)//2

            # print(nums[left], nums[mid], nums[right])

            
        
        return ans