class Solution { // 04.19 11:21~11:37
public:
    int maximumWealth(vector<vector<int>>& accounts) {
    
        int max = 0;
        vector<int> eachWealth;
        
        for(int i=0;i<accounts.size();i++){
            int eachSum=0; 
            for(int j=0;j<accounts[i].size();j++){
                eachSum += accounts[i][j];
            }
            eachWealth.push_back(eachSum);
        }
        
        for(int i=0;i<eachWealth.size();i++){
            if(max<eachWealth[i])
                max = eachWealth[i];
        }
        return max;
    }
};

// 2차원 벡터에 관한 문제
