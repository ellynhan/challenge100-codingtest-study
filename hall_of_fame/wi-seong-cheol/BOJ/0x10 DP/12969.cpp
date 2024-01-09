//
//  12969.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 15 36
 [Output]
 AAAAAAAAAAAABBB
 */
// 시간복잡도: O(2^(n / 2))
// 최악시간: 1,048,576
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12969

#include <iostream>

using namespace std;
int n, k;
char ans[31];
bool dp[31][31][31][450];

void solve(int len, int a, int b, int p) {
    if(len == n) {
        if(p == k) {
            cout << ans;
            exit(0);
        }
        return;
    }

    if(dp[len][a][b][p]) return;

    dp[len][a][b][p] = true;
    ans[len] = 'A';
    solve(len + 1, a + 1, b, p);
    ans[len] = 'B';
    solve(len + 1, a, b + 1, p + a);
    ans[len] = 'C';
    solve(len + 1, a, b, p + a + b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    solve(0, 0, 0, 0);
    cout << -1;

	return 0;
}
