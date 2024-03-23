//
//  1652.cpp
//  main
//
//  Created by wi_seong on 3/17/24.
//

/*
 [Input]
 5
 ....X
 ..XX.
 .....
 .XX..
 X....
 [Output]
 5 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 20,000
// 난이도: Silver 5
// Timer: 7m
// Url: https://www.acmicpc.net/problem/1652

#include <iostream>

using namespace std;
int n;
int cnt[2];
string board[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if((j == 0 || board[i][j - 1] == 'X') &&
               board[i][j] == '.' && board[i][j + 1] == '.') {
                cnt[0]++;
                j++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if((j == 0 || board[j - 1][i] == 'X') &&
               board[j][i] == '.' && board[j + 1][i] == '.') {
                cnt[1]++;
                j++;
            }
        }
    }
    cout << cnt[0] << " " << cnt[1];

	return 0;
}
