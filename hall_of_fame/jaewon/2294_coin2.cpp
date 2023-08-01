#include <iostream>
#include <algorithm>
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
    sort(coins, coins+n);
    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=k; j++){
            if(j%coins[i]==0){
                if(dp[j]==0){
                    dp[j]=j/coins[i];
                }else{
                    dp[j] = min(dp[j],j/coins[i]);
                }
            }else if(dp[j-coins[i]]!=0){
                if(dp[j]==0){
                    dp[j]=dp[j-coins[i]]+1;
                }else{
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
            }
        }
    }
    if(dp[k]==0){
        cout<<-1;
    }else{
        cout<<dp[k];
    }
}
