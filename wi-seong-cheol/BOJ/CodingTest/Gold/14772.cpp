//
//  14772.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 2
 0 2
 0 0
 [Output]
 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14772

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int board[1001][1001];
int d[1001][1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0)
                d[i][j][0] = 1;
        }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                d[i][j][0] = max(d[i][j][0], d[i][j - 1][0]);
                d[i][j][1] = max(d[i][j][1], d[i][j - 1][1]);
                d[i][j][2] = max(d[i][j][2], d[i][j - 1][2]);

                if(board[i][j] == 0) {
                    if(d[i][j - 1][2] != 0)
                        d[i][j][0] = max(d[i][j][0], d[i][j - 1][2] + 1);
                } else if(board[i][j] == 1) {
                    if(d[i][j - 1][0] != 0)
                        d[i][j][1] = max(d[i][j][1], d[i][j - 1][0] + 1);
                } else {
                    if(d[i][j - 1][1] != 0)
                        d[i][j][2] = max(d[i][j][2], d[i][j - 1][1] + 1);
                }
            } else if(j == 0) {
                d[i][j][0] = max(d[i][j][0], d[i - 1][j][0]);
                d[i][j][1] = max(d[i][j][1], d[i - 1][j][1]);
                d[i][j][2] = max(d[i][j][2], d[i - 1][j][2]);

                if(board[i][j] == 0) {
                    if(d[i - 1][j][2] != 0)
                        d[i][j][0] = max(d[i][j][0], d[i - 1][j][2] + 1);
                } else if(board[i][j] == 1) {
                    if(d[i - 1][j][0] != 0)
                        d[i][j][1] = max(d[i][j][1], d[i - 1][j][0] + 1);
                } else {
                    if(d[i - 1][j][1] != 0)
                        d[i][j][2] = max(d[i][j][2], d[i - 1][j][1] + 1);
                }
            } else {
                d[i][j][0] = max({d[i][j][0], d[i - 1][j][0], d[i][j - 1][0]});
                d[i][j][1] = max({d[i][j][1], d[i - 1][j][1], d[i][j - 1][1]});
                d[i][j][2] = max({d[i][j][2], d[i - 1][j][2], d[i][j - 1][2]});

                if(board[i][j] == 0) {
                    if(d[i - 1][j][2] != 0)
                        d[i][j][0] = max(d[i][j][0], d[i - 1][j][2] + 1);
                    if(d[i][j - 1][2] != 0)
                        d[i][j][0] = max(d[i][j][0], d[i][j - 1][2] + 1);
                } else if (board[i][j] == 1) {
                    if(d[i - 1][j][0] != 0)
                        d[i][j][1] = max(d[i][j][1], d[i - 1][j][0] + 1);
                    if(d[i][j - 1][0] != 0)
                        d[i][j][1] = max(d[i][j][1], d[i][j - 1][0] + 1);
                } else {
                    if(d[i - 1][j][1] != 0)
                        d[i][j][2] = max(d[i][j][2], d[i - 1][j][1] + 1);
                    if(d[i][j - 1][1] != 0)
                        d[i][j][2] = max(d[i][j][2], d[i][j - 1][1] + 1);
                }
            }
        }
    }
    cout << max({d[n - 1][n - 1][0], d[n - 1][n - 1][1], d[n - 1][n - 1][2]});
    
    return 0;
}
