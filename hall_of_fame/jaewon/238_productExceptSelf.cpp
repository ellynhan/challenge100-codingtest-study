class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer (n,1);
        int left = nums[0], right = nums[n-1];
        for(int i=1; i<=n-1; i++){
            answer[i] = left;
            left *= nums[i];
        }
        for(int i=n-2; i>=0; i--){
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};