//
//  1931.cpp
//  main
//
//  Created by wi_seong on 3/18/24.
//

/*
 [Input]
 7 5
 49 26 27 28 29 30 31
 48 25 10 11 12 13 32
 47 24 9 2 3 14 33
 46 23 8 1 4 15 34
 45 22 7 6 5 16 35
 44 21 20 19 18 17 36
 43 42 41 40 39 38 37
 [Output]
 5 7
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1931

#include <iostream>

using namespace std;
int n, k;
int board[1000][1000];

void solve() {
    int idx = n * n;
    int len = n - 1;
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < len; j++) {
            board[i + j][i] = idx--;
        }
        for(int j = 0; j < len; j++) {
            board[n - i - 1][i + j] = idx--;
        }
        for(int j = 0; j < len; j++) {
            board[n - j - 1 - i][n - i - 1] = idx--;
        }
        for(int j = 0; j < len; j++) {
            board[i][n - j - 1 - i] = idx--;
        }

        len -= 2;
    }
    board[n / 2][n / 2] = idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    solve();
    int x, y;
    x = y = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
            if(board[i][j] == k) {
                x = i + 1;
                y = j + 1;
            }
        }
        cout << '\n';
    }
    cout << x << ' ' << y;

	return 0;
}
