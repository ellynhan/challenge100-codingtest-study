#include <iostream>
#include <bitset>
using namespace std;
int n; // 2 ~ 16
int W[16][16];
int dp[16][1<<16]; //현재도시, checkBit
int dfs(int curr, int bit){
    if(dp[curr][bit]!=INT32_MAX){
        return dp[curr][bit];
    }
    if(bit == (1<<n)-1 && W[curr][0]!=0){
        return W[curr][0];
    }
    for(int i=0; i<n; i++){
        if(bit&(1<<i)||W[curr][i]==0)continue;
        int tmp = dfs(i,bit|(1<<i));
        if(tmp!=INT32_MAX){
            dp[curr][bit] = min(dp[curr][bit], tmp + W[curr][i]);
        }
    }
    return dp[curr][bit];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> W[i][j];
        }
        for(int j=0; j<(1<<n); j++){
            dp[i][j]=INT32_MAX;
        }
    }
    cout<<dfs(0,1);
}
