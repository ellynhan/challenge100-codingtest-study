#include<bits/stdc++.h>

using namespace std;

int n;
// dp[2]에서 dp[0]이 1이어야해서 1로 초기화
int dp[1001] = {1, };

int main() {
    cin >> n;

    // 초기 조건
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        // 2x1로 시작하는 경우, 1x2로 시작하는 경우
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout << dp[n] << endl;
}
