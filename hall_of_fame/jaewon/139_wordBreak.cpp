class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(int i=0; i<wordDict.size(); i++){
            dict.insert(wordDict[i]);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0; i<s.size(); i++){
            for(int j=1; j<=s.size()-i; j++){
                if(dp[i] && dict.count(s.substr(i,j))>0){
                    dp[i+j] = true;
                }
            }
        }
        return dp[s.size()];
        
        /* Discussion 답안
        if(dict.size()==0) return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j] == true){
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end()){
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        return dp[s.size()]; */
    }
};