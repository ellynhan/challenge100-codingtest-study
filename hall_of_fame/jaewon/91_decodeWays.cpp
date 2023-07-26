class Solution {
public:
    map<string,int> dp;
    int dfs(string s){
        int len = s.length();
        if(dp.count(s)>0)return dp[s];
        if(len == 2){
            int num = stoi(s);
            if((num%10==0 && num > 20)||s[0]=='0'){
                dp[s]=0;
                return 0;
            }else if(num%10==0 || num > 26){
                dp[s]=1;
                return 1;
            }else{
                dp[s]=2;
                return 2;
            }
        }else if(len == 1){
            int num = stoi(s);
            if(num==0){
                return 0;
            }else{
                return 1;
            }
        }else{
            string frontOne = s.substr(0,1);
            if(frontOne == "0") return 0;
            int ret1 = dfs(s.substr(1,len-1));
            dp[s] = ret1;
            string frontTwo = s.substr(0,2);
            if(stoi(frontTwo) > 26) return dp[s];
            int ret2 = dfs(s.substr(2,len-2));
            dp[s] += ret2;

        }
        return dp[s];
    }
    
    int numDecodings(string s) {
        return dfs(s);
    }
};