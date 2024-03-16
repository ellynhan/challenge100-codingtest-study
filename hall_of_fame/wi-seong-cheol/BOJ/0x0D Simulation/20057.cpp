//
//  20057.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/29/23.
//

/*
 [Input]
 5
 0 0 0 0 0
 0 0 0 0 0
 0 10 0 0 0
 0 0 0 0 0
 0 0 0 0 0
 [Output]
 10
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20057

#include <iostream>

using namespace std;
int n, ans;
int board[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int xdx[4][10] = {
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}
};
int ydy[4][10] = {
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
    { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};
int percent[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5} ;

int changeDir(int dir) {
    if(dir == 0) return 3;
    else if(dir == 1) return 2;
    else if(dir == 2) return 0;
    else return 1;
}

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > n; }

void spreadSand(int x, int y,int dir) {
    int xx = x + dx[dir];
    int yy = y + dy[dir];
    if(board[xx][yy] == 0) return;

    int sand = board[xx][yy];
    int tmp = sand;
    for(int i = 0; i < 9; i++) {
        int nx = x + xdx[dir][i];
        int ny = y + ydy[dir][i];
        int per = percent[i];
        int plus = (tmp * per) / 100;

        if(OOB(nx, ny)) ans += plus;
        else board[nx][ny] += plus;

        sand -= plus;
    }
    int nx = x + xdx[dir][9];
    int ny = y + ydy[dir][9];

    if(OOB(nx, ny)) ans += sand;
    else board[nx][ny] += sand;
    board[xx][yy] = 0;
}

void solve() {
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int dir = 1;
    int moveCnt = 1;

    while(1) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < moveCnt; j++) {
                spreadSand(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            dir = changeDir(dir);
        }
        moveCnt++;
        if(moveCnt == n) {
            for(int j = 0; j < moveCnt; j++) {
                spreadSand(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    solve();
    cout << ans;

    return 0;
}
