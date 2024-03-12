//
//  14890.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 6 2
 3 2 1 1 2 3
 3 2 2 1 2 3
 3 2 2 2 3 3
 3 3 3 3 3 3
 3 3 3 3 2 2
 3 3 3 3 2 2
 [Output]
 7
 */
// 시간복잡도: O(2n * l)
// 최악시간: 20,000
// 난이도: Gold 3
// Timer: 35m
// Url: https://www.acmicpc.net/problem/14890

#include <iostream>

using namespace std;
int answer;
int n, L;
int board[201][101];

void solve() {
    int i, j;
    for(i = 0; i < 2 * n; i++) {
        int count = 1;
        for(j = 0; j < n - 1; j++) {
            if(board[i][j] == board[i][j + 1]) {
                count++;
            } else if(board[i][j] == board[i][j + 1] + 1 && count >= 0) {
                count = 1 - L;
            } else if(board[i][j] == board[i][j + 1] - 1 && count >= L) {
                count = 1;
            } else {
                break;
            }
        }
        if(j == n - 1 && count >= 0) {
            answer++;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> L;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[n + i][j] = board[j][i];
        }
    }

    solve();

    cout << answer;

	return 0;
}
