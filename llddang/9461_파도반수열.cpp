#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    int tc[T];
    int maxValue = 8;
    for(int i=0; i<T; i++){
        int tmp; cin >> tmp;
        tc[i] = tmp;
        maxValue = max(maxValue, tmp);
    }

    long long dp[maxValue+1];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;

    for(int i=9; i<=maxValue; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    for(int tmp:tc)
        cout << dp[tmp] << "\n";
}
