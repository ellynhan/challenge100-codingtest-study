class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int MAX = target + 1; // -3일때는?
        
        map<string, int> m;
        vector<int> ret(2);
        for(int i=0; i<n; i++){
            if(m.count(to_string(nums[i]))>0){
                ret[0] = m[to_string(nums[i])];
                ret[1] = i;
                break;
            }else{
                m[to_string(target-nums[i])]=i;
            }
        }
        return ret;
    }
};
