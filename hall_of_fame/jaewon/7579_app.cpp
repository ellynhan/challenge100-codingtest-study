#include <iostream>
using namespace std;
int main(){
    int memories[101];
    int costs[101];
    int dp[101][10001]={0};
    int n, M, maxCost=0;
    scanf("%d%d", &n, &M);
    for(int i=1; i<=n; i++){
        scanf("%d", &memories[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &costs[i]);
        maxCost += costs[i];
        dp[i][costs[i]]=memories[i];
    }
    int minCost = 100000000;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=maxCost; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j>costs[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-costs[i]]+memories[i]);
            }
            if(dp[i][j]>=M){
                minCost = min(minCost, j);
            }
        }
    }

    printf("%d", minCost);
}
