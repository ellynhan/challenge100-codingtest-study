class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int answer = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(dp[i-1]>0){
                dp.push_back(dp[i-1]+nums[i]);
            }else{
                dp.push_back(nums[i]);
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};
