class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[401] = {0};
        int n = nums.size();
        int maxValue = 0;
        if(n >= 1){
            dp[0] = nums[0];
            maxValue = max(maxValue, dp[0]);
        }
        if(n >=2){
            dp[1] = max(nums[0], nums[1]);
            maxValue = max(maxValue, dp[1]);
        }
        if(n >=3){
            dp[2] = max(nums[0]+nums[2], nums[1]);
            maxValue = max(maxValue, dp[2]);
        }
        if(n >= 4){
            for(int i=3; i<n; i++){
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
                maxValue = max(maxValue, dp[i]);
            }
        }
        return maxValue;
    }
};