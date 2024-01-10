//
//  JUMPGAME.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 2
 7
 2 5 1 6 1 4 1
 6 1 1 2 2 9 3
 7 2 3 2 1 3 1
 1 1 3 1 7 1 2
 4 1 2 3 4 1 2
 3 3 1 2 3 4 1
 1 5 2 9 4 7 0
 7
 2 5 1 6 1 4 1
 6 1 1 2 2 9 3
 7 2 3 2 1 3 1
 1 1 3 1 7 1 2
 4 1 2 3 4 1 3
 3 3 1 2 3 4 1
 1 5 2 9 4 7 0
 [Output]
 YES
 NO
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 하
// Timer: 10m
// Url: https://algospot.com/judge/problem/read/JUMPGAME

#include <iostream>
#include <cstring>

using namespace std;
int t, n;
int board[101][101];
int dp[101][101];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void init() {
    memset(board, 0, sizeof(board));
    memset(dp, 0, sizeof(dp));
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
}

void solve() {
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!dp[i][j]) continue;
            int jump = board[i][j];
            if(!OOB(i + jump, j)) dp[i + jump][j] = 1;
            if(!OOB(i, j + jump)) dp[i][j + jump] = 1;
        }
    }
}

void output() {
    if(dp[n - 1][n - 1]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        input();
        solve();
        output();
    }

	return 0;
}
