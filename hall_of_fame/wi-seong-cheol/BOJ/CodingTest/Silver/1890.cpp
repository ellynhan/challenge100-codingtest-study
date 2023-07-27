//
//  1890.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/19.
//

/*
 [Input]
 4
 2 3 3 1
 1 2 1 3
 1 2 3 1
 3 1 1 0
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1890

#include <iostream>

using namespace std;
#define ll long long
int n;
int board[101][101];
ll d[101][101];
int dx[] = {0, 1};
int dy[] = {1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    d[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i == n - 1 && j == n - 1) continue;
            if(d[i][j] == 0) continue;
            for(int dir = 0; dir < 2; dir++) {
                int nx = i + dx[dir] * board[i][j];
                int ny = j + dy[dir] * board[i][j];
                if(OOB(nx, ny)) continue;
                d[nx][ny] += d[i][j];
            }
        }
    cout << d[n - 1][n - 1];
    
    return 0;
}
