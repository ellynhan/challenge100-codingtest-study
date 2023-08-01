class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[1001][1001]={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = i>0 && j>0 ? dp[i-1][j-1]+1 : 1;
                }else{
                    if(i>0){
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    }
                    if(j>0){
                        dp[i][j] = max(dp[i][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};

/* solution of discussion
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        dp[i+1][j+1] = text1[i] == text2[j] ? dp[i][j] +1 : max(dp[i+1][j], dp[i][j+1]);
    }
}
return dp[n][m];
=> 현재의 결과를 미래에 저장

내 방식은 과거의 결과에 현재의 결과를 저장.
그러다보니 중복발생시 문제가 있었음............. 
*/