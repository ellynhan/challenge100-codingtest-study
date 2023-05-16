class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int num = 0;
        for(int i=0;i<nums.size();i++){
            result.push_back(num+=nums[i]);
        }
        return result;
    }
};

// 1차원 벡터 관련
