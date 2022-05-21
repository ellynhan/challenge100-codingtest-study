#include<bits/stdc++.h>

using namespace std;

int T, n, result;
int dp[11] = {0, };

void solve(int k) {
    result = dp[k-1];
    result += dp[k-2];
    result += dp[k-3];
    dp[k] = result;
}

int main() {
    cin >> T;

    // 초기 조건
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    while(T--) {
        cin >> n;
        for(int i=4; i<=n; i++) {
            if(dp[i] == 0) solve(i);
        }
        cout << dp[n] << endl;
    }
}
