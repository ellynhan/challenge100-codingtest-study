//
//  1051.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 11 10
 9785409507
 2055103694
 0861396761
 3073207669
 1233049493
 2300248968
 9769239548
 7984130001
 1670020095
 8894239889
 4053971072
 [Output]
 49
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 2,500
// 난이도: Silver 3
// Timer: 12m
// Url: https://www.acmicpc.net/problem/1051

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int L = min(n, m);
    for(int len = L; len > 0; len--) {
        for(int i = 0; i < n - len + 1; i++) {
            for(int j = 0; j < m - len + 1; j++) {
                if(board[i][j] == board[i + len - 1][j] &&
                   board[i][j] == board[i][j + len - 1] &&
                   board[i][j] == board[i + len - 1][j + len - 1]) {
                    cout << len * len;
                    return 0;
                }
            }
        }
    }

	return 0;
}
