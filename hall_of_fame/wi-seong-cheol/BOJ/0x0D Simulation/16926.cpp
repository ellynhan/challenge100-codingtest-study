//
//  16926.cpp
//  main
//
//  Created by wi_seong on 3/15/24.
//

/*
 [Input]
 4 4 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 [Output]
 3 4 8 12
 2 11 10 16
 1 7 6 15
 5 9 13 14
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 90,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/16926

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, r;
int board[301][301];

void rotate(int i, int j, int a, int b) {
    int tmp = board[i][j];
    for(int k = j; k < b; k++) {
        board[i][k] = board[i][k + 1];
    }
    for(int k = i; k < a; k++) {
        board[k][b] = board[k + 1][b];
    }
    for(int k = b; k > j; k--) {
        board[a][k] = board[a][k - 1];
    }
    for(int k = a; k > i; k--) {
        board[k][j] = board[k - 1][j];
    }
    board[i + 1][j] = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while(r--) {
        for(int i = 0; i < min(n, m) / 2; i++) {
            rotate(i, i, n - i - 1, m - i - 1);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

	return 0;
}
