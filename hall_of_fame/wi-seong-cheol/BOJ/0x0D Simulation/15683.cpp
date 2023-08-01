//
//  15683.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 6
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 1 0 6 0
 0 0 0 0 0 0
 [Output]
 20
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 25,165,824
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15683

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m, mn;
int board1[10][10];
int board2[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> cctv;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void upd(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x, y) || board2[x][y] == 6) return;
        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});
            if(board1[i][j] == 0) mn++;
        }
    
    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x,y;
            tie(x, y) = cctv[i];
            if(board1[x][y] == 1) {
                upd(x, y, dir);
            } else if(board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            } else if(board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            } else if(board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            } else {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (board2[i][j] == 0);
        mn = min(mn, val);
    }
    cout << mn;
    
    return 0;
}
