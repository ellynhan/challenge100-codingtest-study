#include <iostream>
#include <bitset>
using namespace std;
int n; 
long long dp[101][10][1<<10]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=1; i<10; i++){
        dp[1][i][1<<i]  = 1;
    }

    for(int k=2; k<=n; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<1024; j++){
                if(i==0){
                    dp[k][i][j|1] += dp[k-1][1][j]%1000000000;
                }else if(i==9){
                    dp[k][i][j|1<<9] += dp[k-1][8][j%1000000000];
                }else{
                    dp[k][i][j|1<<i] += dp[k-1][i-1][j]%1000000000;
                    dp[k][i][j|1<<i] += dp[k-1][i+1][j]%1000000000;
                }
            }
        }
    }
    for(int k=2; k<=n; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<1024; j++){
                dp[k][i][j]%=1000000000;
            }
        }
    }

    long long answer = 0;
    for(int i=0; i<10; i++){
        answer += dp[n][i][1023]%1000000000;
    }
    cout<<answer%1000000000;
}
/*
answer = dp[n][0][1023] + dp[n][1][1023] + ... + dp[n][9][1023];
answer%t = ((dp[n][0][1023]%t) + (dp[n][1][1023]%t) + ... + (dp[n][9][1023]%t))%t
dp[n][0][1023] = dp[k][i][j]+~~dp[k][i][j]
dp[n][0][1023]%t = (dp[k][i][j]%t + ... dp[k][i][j]%t .. )%t
*/
