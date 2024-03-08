//
//  15684.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 5 6 6
 1 1
 3 1
 5 2
 4 3
 2 3
 1 4
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 7,200
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15684

#include <iostream>
#include <algorithm>

using namespace std;
int answer = 4;
int n, m, h;
int board[31][11];

bool isCheck() {
    for(int i = 1; i <= n; i++) {
        int y = i;
        for(int j = 1; j <= h; j++) {
            if(board[j][y] == 1) y++;
            else if(board[j][y - 1] == 1) y--;
        }
        if(y != i) return false;
    }
    return true;
}

void solve(int k, int x, int y) {
    if(k >= answer) return;
    if(isCheck()) {
        answer = k;
        return;
    }
    if(k == 3) return;

    for(int i = x; i <= h; i++) {
        for(int j = y; j < n; j++) {
            if(board[i][j] == 1) continue;
            if(board[i][j - 1] == 1) continue;
            if(board[i][j + 1] == 1) continue;
            board[i][j] = 1;
            solve(k + 1, i, j);
            board[i][j] = 0;
        }
        y = 1;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    solve(0, 1, 1);
    if(answer == 4) cout << -1;
    else cout << answer;

	return 0;
}
