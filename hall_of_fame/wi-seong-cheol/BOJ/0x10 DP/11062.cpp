//
//  11062.cpp
//  main
//
//  Created by wi_seong on 1/4/24.
//

/*
 [Input]
 2
 4
 1 2 5 2
 9
 1 1 1 1 2 2 2 2 2
 [Output]
 6
 8
 */
// 시간복잡도: O(n)
// 최악시간: 5,000,0000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/11062

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int t, n;
int card[1001];
int dp[1001][1001];

int play(int left, int right, int turn) {
    if(left > right) return 0;
    if(dp[left][right]) return dp[left][right];
    if(turn % 2) {
        dp[left][right] = max(play(left + 1, right, turn + 1) + card[left], play(left, right - 1, turn + 1) + card[right]);
    } else {
        dp[left][right] = min(play(left + 1, right, turn + 1), play(left, right - 1, turn + 1));
    }
    return dp[left][right];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> card[i];
        play(0, n - 1, 1);
        cout << dp[0][n - 1] << '\n';
        memset(dp, 0, sizeof(dp));
    }

	return 0;
}
