//
//  11660.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 4 3
 1 2 3 4
 2 3 4 5
 3 4 5 6
 4 5 6 7
 2 2 3 4
 3 4 3 4
 1 1 4 4
 [Output]
 27
 6
 64
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 3m
// Url: https://www.acmicpc.net/problem/11660

#include <iostream>

using namespace std;
int n, m;
int board[1025][1025];
int psum[1025][1025];

void calc() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + board[i][j];
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    calc();
    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
        cout << sum << '\n';
    }

	return 0;
}
