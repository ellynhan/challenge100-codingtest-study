#include <bits/stdc++.h>

using namespace std;

int N, x;
int dp[1000001] ={0, };
int result;

void solve() {
    // 셋 연산 중 가장 적은 횟수 찾기
    result = dp[x-1] + 1;
    if(x%3==0) { result = min(result, dp[x/3] + 1); }
    if(x%2==0) { result = min(result, dp[x/2] + 1); }
    dp[x] = result;
}

int main() {
    cin >> N;

    // 초기 조건
    //dp[1] = 0; 주의) 1일 때 답은 1이 아니라 0이다!!
    dp[2] = 1;
    dp[3] = 1;

    // dp그래프 채우기
    for(x=4; x<=N; x++) {
        solve();
    }
    cout << dp[N] << endl;

    return 0;
}
