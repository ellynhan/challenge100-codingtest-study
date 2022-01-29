class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val len1 = nums1.size
        val len2 = nums2.size
        val result = len1 + len2
        
        var num = IntArray(result)
        var index1 = 0
        var index2 = 0
        
        while(index1 < len1 && index2 < len2) {
            if(nums1[index1] <= nums2[index2]) {
                num[index1 + index2] = nums1[index1]
                index1 += 1
            } else {
                num[index1+index2] = nums2[index2]
                index2 += 1
            }
        }
        
        while(index1 < len1) {
            num[index1 + index2] = nums1[index1]
            index1 += 1
        }
        
        while(index2 < len2) {
            num[index1 + index2] = nums2[index2]
            index2 += 1
        }
        
        if(result % 2 == 0) {
            return (num[result / 2 - 1] + num[result / 2]) / 2.0
        } else {
            return num[result / 2] / 1.0
        }
    }
}