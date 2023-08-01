#include <iostream>
using namespace std;

int dp[10001]={0};

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n,k;

    cin >> n >> k;
    int* coins = new int[n];
    for(int i=0; i<n; i++){
        int coin;
        cin >> coin;
        coins[i] = coin;
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=k; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    cout<<dp[k];
}
