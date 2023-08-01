//
//  11559.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 ......
 ......
 ......
 ......
 ......
 ......
 ......
 ......
 .Y....
 .YG...
 RRYG..
 RRYGG.
 [Output]
 3
 */
// 시간복잡도: O(n^3 * m^3)
// 최악시간: 373,248
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/11559

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int cnt;
string board[13];
bool isPuyo;
bool vis[13][7];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void initVis() {
    for(int i = 0; i < 12; i++)
        fill(vis[i], vis[i] + 6, false);
}

bool OOB(int x, int y) { return x < 0 || x >= 12 || y < 0 || y >= 6; }

void puyo(int x, int y) {
    queue<pair<int, int>> Q;
    vector<pair<int, int>> tmp;
    Q.push({x, y});
    tmp.push_back({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] != board[x][y]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
            tmp.push_back({nx, ny});
        }
    }
    if(tmp.size() >= 4) {
        isPuyo = true;
        for(auto cur: tmp)
            board[cur.X][cur.Y] = '.';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 12; i++)
        cin >> board[i];
    do {
        isPuyo = false;
        for(int i = 0; i < 6; i++) {
            for(int j = 10; j >= 0; j--) {
                int tmp = j;
                while(tmp < 11 && board[tmp + 1][i] == '.') {
                    swap(board[tmp][i], board[tmp + 1][i]);
                    tmp++;
                }
            }
        }
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 6; j++)
                if(!vis[i][j] && board[i][j] != '.')
                    puyo(i, j);
        if(isPuyo) cnt++;
        initVis();
    } while(isPuyo);
    cout << cnt;
    
    return 0;
}
