class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if n:
            n_index = 0
            for i in range(len(nums1)):
                if nums1[i] == 0 and n :
                    nums1[i] = nums2[n_index]
                    n_index += 1
                    n -= 1
        nums1.sort()     


#정답 : 병합정렬은 배열을 미리 주어두고, 정렬을 수행. 새로운 배열 생성 X
# 

    def merge1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        for i in range(n):
            num1[i+m] = num2[i]

        num1.sort()    