class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())swap(nums1, nums2);
        
        int n = nums1.size();
        int m = nums2.size();
        
        int low = 0, high = n;
        while(low <= high){
            int cut1 = (low + high)/2;
            int cut2 = (n+m)/2-cut1;
            
            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            int right1 = cut1==n ? INT_MAX : nums1[cut1];
            int right2 = cut2==m ? INT_MAX : nums2[cut2];
            
            if(left1 > right2) high = cut1 - 1;
            else if(left2 > right1) low = cut1 + 1;
            else return (n+m)%2!=0 ? min(right1, right2) : (max(left1, left2) + min(right1, right2))/2.;
        }
        return -1;
    }
};
