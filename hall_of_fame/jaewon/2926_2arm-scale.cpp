#include <iostream>
using namespace std;
int main(){
    int weights[30];
    int checks[7];
    int dp[31][80001]={0};
    int numOfWeight, numOfCheck;
    
    scanf("%d",&numOfWeight);

    for(int i=0; i<numOfWeight; i++){
        scanf("%d",&weights[i]);
        dp[i+1][weights[i]+40000]=1;
        dp[i+1][-weights[i]+40000]=1;
    }

    scanf("%d",&numOfCheck);

    for(int i=0; i<numOfCheck; i++){
        scanf("%d",&checks[i]);
    }
    
    //knapsack
    int currMax = 0;
    for(int i=1; i<=numOfWeight; i++){
        currMax += weights[i-1];
        for(int j=1; j<=currMax+40000; j++){
            if(dp[i-1][j]==1 || dp[i-1][j-weights[i-1]]==1 || dp[i-1][j+weights[i-1]]==1){
                dp[i][j]=1;
                continue;
            }        
        }
    }

    for(int i=0; i<numOfCheck; i++){
        if(dp[numOfWeight][checks[i]+40000]==1){
            printf("Y ");
        }else{
            printf("N ");
        }
    }
}
