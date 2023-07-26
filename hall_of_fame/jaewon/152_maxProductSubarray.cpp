class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp[20001][2]={0};
        int answer = nums[0];
        
        if(nums[0]<0){
            dp[0][1] = nums[0];
        }else{
            dp[0][0] = nums[0];
        }
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==0){
                dp[i][0]=0;
            }else if(nums[i]>0){
                dp[i][0]=max(nums[i],dp[i-1][0]*nums[i]);
                dp[i][1]=dp[i-1][1]*nums[i];
            }else{
                dp[i][0] = max (0, dp[i-1][1]*nums[i]);
                if(dp[i-1][0]!=0){
                    dp[i][1] = dp[i-1][0]*nums[i];
                }else{
                    dp[i][1] = nums[i];
                }
            }
            answer = max(answer, max(dp[i][0],dp[i][1]));
        }
        return answer;   
    }
};