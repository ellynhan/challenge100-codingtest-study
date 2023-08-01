//
//  17144.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 8 30
 0 0 0 0 0 0 0 9
 0 0 0 0 3 0 0 8
 -1 0 5 0 0 0 22 0
 -1 8 0 0 0 0 0 0
 0 0 0 0 0 10 43 0
 0 0 5 0 15 0 0 0
 0 0 40 0 0 0 20 0
 [Output]
 52
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17144

#include <iostream>
#include <cstring>

using namespace std;
#define X first
#define Y second
int ans;
int R, C, T;
int board[51][51];
int machine_bottom;    // 공기청정기 아래 위치
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cdx[] = {0, -1, 0, 1};
int cdy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= R || y < 0 || y >= C; }

void move() {   // 미세먼지 이동
    
    int nxt[R][C];
    memset(nxt, 0, sizeof(nxt));
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++) {
            if(board[i][j] > 0) {
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(OOB(nx, ny) || board[nx][ny] == -1) continue;
                    cnt++;
                    nxt[nx][ny] += board[i][j] / 5;
                }
                board[i][j] -= (board[i][j] / 5) * cnt;
            }
        }
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            board[i][j] += nxt[i][j];
    
}

void clockwise_wind(int i, int j, int dir, int prev_dust) {
    if(board[i][j] == -1) return;
    
    auto move_dust = board[i][j];
    board[i][j] = prev_dust;
    auto x = i + dx[dir];
    auto y = j + dy[dir];
    if(OOB(x, y)) {
        dir++;
        x = i + dx[dir];
        y = j + dy[dir];
        clockwise_wind(x, y, dir, move_dust);
    }
    else
        clockwise_wind(x, y, dir, move_dust);
}

void counter_clockwise_wind(int i, int j, int dir, int prev_dust) {
    if(board[i][j] == -1) return;
    
    auto move_dust = board[i][j];
    board[i][j] = prev_dust;
    auto x = i + cdx[dir];
    auto y = j + cdy[dir];
    if(OOB(x, y)) {
        dir++;
        x = i + cdx[dir];
        y = j + cdy[dir];
        counter_clockwise_wind(x, y, dir, move_dust);
    }
    else
        counter_clockwise_wind(x, y, dir, move_dust);
}

void puri() {   // 공기 정화
    int x2 = machine_bottom;
    int x1 = machine_bottom - 1;
    
    counter_clockwise_wind(x1, 1, 0, 0);
    clockwise_wind(x2, 1, 0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            if(board[i][j] == -1)
                machine_bottom = i;
        }
    while(T--) {
        move();
        puri();
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(board[i][j] != -1)
                ans += board[i][j];
    cout << ans;
    
    return 0;
}
