class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        import math

        length = len(nums) ## 길이
        ans = [1] * length ## 1 로된 리스트
        zerocnt = nums.count(0) ## 제로가 몇갠지

        if zerocnt > 1:         ## 2개
            ans = [0] * length  ## [0 1221 0 ]

        elif zerocnt == 1:          ## 1개
            ans = [0] * length      ## 싹다 영
            zeroidx = nums.index(0) ## 0 인덱스 뽑아서 왜냐면 0에만 값있으니까
            ans[zeroidx] = math.prod(nums[0:zeroidx]) * math.prod(nums[zeroidx+1:])

        else:                   ## 0이 없으면
            pre, suf = 1, 1     ## 보고 있는 값 앞뒤로 pre suf

            for i in range(length): ## 하나씩 돌면서

                if i > 0:               ## nums = [1,2,3,4]
                    pre *= nums[i-1]   ## [1] [1, 2] [1,2,3] 
                    suf *= nums[-i]   ## [4] [3, 4] [2,3,4]

                ans[i] *= pre
                ans[-i-1] *= suf

        return ans          ## abcd  c 의 prefix suffix substing