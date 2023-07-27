class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        for(int i=0; i<n-2; i++){
            int target = -nums[i];
            int front = i+1;
            int back = n-1;
            
            while(front < back){
                int sum = nums[front]+nums[back];
                if(sum > target){
                    back --;
                }
                else if(sum == target){
                    int dupF=front, dupB = back;
                    ans.push_back({nums[i], nums[front], nums[back]});
                    while (dupF < dupB && nums[dupF] == nums[front]) dupF++;
                    while (dupF < dupB && nums[dupB] == nums[back]) dupB--;
                    front = dupF;
                    back = dupB;
                }else{
                    front ++;
                }
            }
            while(i<n-2&&nums[i+1]==nums[i]){i++;}
        } 
        return ans;
    }
};