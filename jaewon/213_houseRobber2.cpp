class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();
        int maxValue = 0;
        int dp[1001][2] = {0};
        //무조건 0번째를 터는 경우 -> n-1번째 털기 불가
        dp[0][0] = nums[0];
        //무조건 0번째를 털지 않는 경우 -> n-1번째 털기 가능
        dp[0][1] = 0;
        maxValue = dp[0][0];
        if(n>=2){
            //0 1
            dp[1][0] = dp[0][0];
            dp[1][1] = nums[1];
            maxValue = max(dp[1][0], dp[1][1]);
        }
        if(n>=3){
            dp[2][0] = dp[1][0];
            dp[2][1] = max(dp[1][1], nums[2]);
            maxValue = max(dp[2][0], dp[2][1]);
        }
        if(n>=4){
            dp[3][0] = max(dp[0][0]+nums[2], dp[2][0]);
            dp[3][1] = max(dp[1][1]+nums[3], nums[2]);
            maxValue = max(dp[3][0], dp[3][1]);
        }
        if(n>=5){
            dp[4][0] = max(dp[0][0]+nums[3], dp[3][0]);
            dp[4][1] = max(dp[2][1]+nums[4], dp[3][1]);
            maxValue = max(dp[4][0], dp[4][1]);
        }
        if(n>=6){
            for(int i=5; i<n; i++){
                dp[i][0] = max(dp[i-2][0]+nums[i-1], dp[i-1][0]);
                dp[i][1] = max(dp[i-2][1]+nums[i], dp[i-1][1]);
                maxValue = max(dp[i][0], dp[i][1]);
            }
        }
        return maxValue;
    }
};