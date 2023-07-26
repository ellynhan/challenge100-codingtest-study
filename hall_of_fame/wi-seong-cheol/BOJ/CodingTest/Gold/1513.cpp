//
//  1513.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/14.
//

/*
 [Input]
 3 3 2
 2 2
 3 2
 [Output]
 1 3 2
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1513

#include <iostream>

using namespace std;
const int mod = 1000007;
int n, m, c, x, y, idx;
int board[51][51];
int d[51][51][51][51]; // 오락실 번호, 갯수, 위치 x, 위치 y

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++) {
        cin >> x >> y;
        board[x][y] = i;
    }

    if((idx = board[1][1]))
        d[1][1][1][idx] = 1;
    else
        d[1][1][0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) continue;
            if((idx = board[i][j])) {
                for(int l = 0; l < idx; l++) {
                    for(int k = 0; k <= l; k++) {
                        d[i][j][k + 1][idx] += d[i - 1][j][k][l] + d[i][j - 1][k][l];
                        d[i][j][k + 1][idx] %= mod;
                    }
                }
            } else {
                for(int l = 0; l <= c; l++) {
                    for(int k = 0; k <= l; k++) {
                        d[i][j][k][l] += d[i - 1][j][k][l] + d[i][j - 1][k][l];
                        d[i][j][k][l] %= mod;
                    }
                }
            }
        }
    }
    for(int i = 0; i <= c; i++) {
        int sum = 0;
        for(int j = 0; j <= c; j++)
            sum += d[n][m][i][j];
        cout << sum % mod << ' ';
    }
    
    return 0;
}
