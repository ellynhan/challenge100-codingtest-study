//
//  4198.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 3
 1
 2
 3
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 4,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/4198

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int dp[2001], f[2001], e[2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> dp[i];
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(dp[i] < dp[j]) e[i] = max(e[i], e[j]);
            else f[i] = max(f[i], f[j]);
        }
        e[i]++;
        f[i]++;
        ans = max(ans, e[i] + f[i] - 1);
    }
    cout << ans;

	return 0;
}
