#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int max_alp=0, max_cop = 0;
    for(auto &problem : problems){
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }
    
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    
    int dp[max_alp + 1][max_cop + 1];
    for(int i=0; i <= max_alp; i++) fill(dp[i], dp[i] + max_cop + 1, 0x7fffffff);
    dp[alp][cop] = 0;
    
    for(int i=alp; i <= max_alp; i++){
        for(int j=cop; j <= max_cop; j++){                
            if(i+1 <= max_alp)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if(j+1 <= max_cop)
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);

            for(auto &problem : problems){
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];
                if(problem[0] <= i && problem[1] <= j){
                    // 문제를 풀었을 때 최대 alp, cop 를 넘어서도 최단 시간이면 갱신
                    int next_alp = min(max_alp, i + alp_rwd);
                    int next_cop = min(max_cop, j + cop_rwd);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost);
                }
            }
        }
    }
    return dp[max_alp][max_cop];
}