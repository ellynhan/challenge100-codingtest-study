#include <bits/stdc++.h>

#define MOD (int) 10e8

using namespace std;

typedef long long ll;

int N;
ll answer;
ll dp[1<<10][101][10];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);                                                                                                
    ios::sync_with_stdio(false);

    cin >> N;

    if (N <= 9) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1<<i][1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int k = 0; k <= 9; k++) {
            for (int j = 0; j < (1 << 10); j++) {
                if (k == 0) {
                    dp[j | (1 << k)][i][k] += dp[j][i - 1][k+1] % MOD;
                } else if (k == 9) {
                    dp[j | (1 << k)][i][k] += dp[j][i - 1][k - 1] % MOD;
                } else {
                    dp[j | (1 << k)][i][k] += (dp[j][i - 1][k + 1] + dp[j][i - 1][k - 1]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++) {
        answer = (answer + dp[(1<<10) - 1][N][i]) % MOD;
    }

    cout << answer;

    return 0;
}

