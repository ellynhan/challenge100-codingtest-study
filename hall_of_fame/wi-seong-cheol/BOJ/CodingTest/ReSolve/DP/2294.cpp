//
//  2294.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 3 15
 1
 5
 12
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 19m
// Url: https://www.acmicpc.net/problem/2294

#include <iostream>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int n, k;
int a[101];
int dp[10001];

void solve() {
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    fill(dp, dp + 10001, INF);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve();
    cout << (dp[k] == INF ? -1 : dp[k]);

	return 0;
}
