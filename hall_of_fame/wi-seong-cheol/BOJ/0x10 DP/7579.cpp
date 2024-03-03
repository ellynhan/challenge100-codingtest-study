//
//  7579.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 19 20169
 240 2560 434 6 31 577 500 2715 2916 952 2490 258 1983 1576 3460 933 1660 2804 2584
 82 77 81 0 36 6 53 78 49 82 82 33 66 8 60 0 98 91 93
 [Output]
 484
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/7579

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m, sum;
pair<int, int> a[101]; // cost, memory
int dp[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].Y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].X;
        sum += a[i].X;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(a[i].X > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].X] + a[i].Y);
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i] >= m) {
            cout << i;
            break;
        }
    }

	return 0;
}
