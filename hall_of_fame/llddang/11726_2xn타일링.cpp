#include <iostream>
using namespace std;

int main(void) {
    int dp[1001];
	int N; cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    int i=3;
    for(; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout << dp[N];
}
