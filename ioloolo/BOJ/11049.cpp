#include <bits/stdc++.h>

using namespace std;

int N;
int arr[501][2];
int dp[501][501];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;
        
        arr[i][0] = r;
        arr[i][1] = c;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = 2e9;
            
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i+j][1]);
            }
        }
    }

    cout << dp[1][N];

    return 0;
}
