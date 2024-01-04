//
//  12920.cpp
//  main
//
//  Created by wi_seong on 1/4/24.
//

/*
 [Input]
 2 3
 2 7 1
 1 9 3
 [Output]
 27
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12920

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, m;
int v, c, k;
int dp[10001];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v >> c >> k;
        int t = 1;
        int tmp;
        while(k > 0) {
            tmp = min(k, t);
            for(int j = m; j >= tmp * v; j--) {
                dp[j] = max(dp[j], dp[j - (tmp * v)] + (tmp * c));
            }
            t *= 2;
            k -= tmp;
        }
    }
    cout << *max_element(dp, dp + m + 1);

	return 0;
}
