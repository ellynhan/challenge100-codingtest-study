#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> W;
vector<int> V;

vector<vector<int>> DP;

int main() {
    cin >> N >> K;

    W.resize(N+1);
    V.resize(N+1);
    DP.assign(N+1, vector<int>(100001));

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            DP[i][j] = j - W[i] >= 0
                       ? max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i])
                       : DP[i][j] = DP[i - 1][j];
        }
    }

    cout << DP[N][K];

    return 0;
}

