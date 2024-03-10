//
//  18111.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 3 4 99
 0 0 0 0
 0 0 0 0
 0 0 0 1
 [Output]
 2 0
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 32,000,000
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/18111

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n, m, block;
int board[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> block;
    int mxHeight = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            mxHeight = max(mxHeight, board[i][j]);
        }
    }

    int t = INT_MAX;
    int h = 0;

    for(int height = 0; height <= mxHeight; height++) {
        int totalBlock = 0;
        int requireBlock = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] > height) totalBlock += board[i][j] - height;
                if(board[i][j] < height) requireBlock += height - board[i][j];
            }
        }
        if(requireBlock > totalBlock + block) continue;
        int totalTime = totalBlock * 2 + requireBlock;
        if(t > totalTime) {
            t = totalTime;
            h = height;
        } else if(t == totalTime) {
            if(h < height) {
                h = height;
            }
        }
    }
    cout << t << ' ' << h;

	return 0;
}
