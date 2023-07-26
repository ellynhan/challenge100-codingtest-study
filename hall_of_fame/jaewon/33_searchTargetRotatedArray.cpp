class Solution {
public:
    int search(vector<int>& nums, int target) {
        return recur(target, 0, nums.size()-1, nums);
    }
    
    int recur(int target, int low, int high, vector<int>& nums){
        if(low > high) return -1;
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] >= nums[low]){
            if(target < nums[low] || target > nums[mid]){
                low = mid+1;
            }else{
                high = mid;
            }
        }else{
            if(target < nums[mid] || target >= nums[low]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return recur(target, low, high, nums);
    }
};