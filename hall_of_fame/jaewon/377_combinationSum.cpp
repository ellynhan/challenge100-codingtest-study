class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        
        for(int i=0; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j] > 0)
                    dp[i] += dp[i-nums[j]];
                else if (i==nums[j])
                    dp[i] += 1;
            }
        }
        return dp[target];
    }
};