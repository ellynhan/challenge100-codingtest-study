//
//  4179.cpp
//  main
//
//  Created by wi_seong on 2022/11/11.
//

/*
 [Input]
 4 4
 ####
 #JF#
 #..#
 #..#
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/4179

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int r, c;
string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];
bool visFire[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    queue<pair<int, int>> Q1, Q2;
    for(int i = 0; i < r; i++) {
        cin >> board[i];
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'F') {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            else if(board[i][j] == 'J') {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    
    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist1[nx][ny] != -1) continue;
            if(board[nx][ny] == '#') continue;
            Q1.push({nx, ny});
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
        }
    }
    
    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny)) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            Q2.push({nx, ny});
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}
