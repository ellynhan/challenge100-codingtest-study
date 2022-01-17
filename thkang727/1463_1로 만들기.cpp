/*
    boj 1463
    dp
*/

#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n>=1 && n<=1000000){
    int dp[n+1];
    dp[0]= 0;
    dp[1]= 0;
    for(int i =2;i<=n;i++){

        dp[i] = dp[i-1]+1;
        if(i%3==0){
            dp[i] = min(dp[i/3]+1,dp[i]);
        }
        if(i%2==0){
            dp[i] = min(dp[i/2]+1,dp[i]);
        }

    }
    cout << dp[n];
    }

    return 0;
}
