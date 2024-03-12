//
//  12100.cpp
//  main
//
//  Created by wi_seong on 3/4/24.
//

/*
 [Input]
 3
 2 2 2
 4 4 4
 8 8 8
 [Output]
 16
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 1,048,576
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12100

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer;
int n;
vector<vector<int>> board;

void rotate() {
    vector<vector<int>> tmp(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir) {
    while(dir--) rotate();
    for(int i = 0; i < n; i++) {
        vector<int> tilted(n, 0);
        int idx = 0;
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) continue;
            if(tilted[idx] == 0)
                tilted[idx] = board[i][j];
            else if(tilted[idx] == board[i][j])
                tilted[idx++] *= 2;
            else
                tilted[++idx] = board[i][j];
        }
        for(int j = 0; j < n; j++) board[i][j] = tilted[j];
    }
}

void solve(int k) {
    if(k == 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                answer = max(answer, board[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> tmp = board;
    for(int dir = 0; dir < 4; dir++) {
        tilt(dir);
        solve(k - 1);
        board = tmp;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    board.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(5);
    cout << answer;

	return 0;
}
