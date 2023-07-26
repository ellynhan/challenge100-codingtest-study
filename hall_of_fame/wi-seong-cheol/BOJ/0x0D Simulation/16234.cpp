//
//  16234.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 2 20 50
 50 30
 20 40
 [Output]
 1
 */
// 시간복잡도: O(n^3)
// 최악시간: 2,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16234

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, l, r;
int board[101][101];
bool vis[101][101];
bool flag = false;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void clearVisit() {
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);
}

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    vector<pair<int, int>> check;
    Q.push({x, y});
    vis[x][y] = true;
    check.push_back({x, y});
    int sum = board[x][y];
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int dif = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(dif >= l && dif <= r){
                flag = true;
                if(!vis[cur.X][cur.Y]){
                    check.push_back({cur.X, cur.Y});
                    sum += board[cur.X][cur.Y];
                    vis[cur.X][cur.Y] = 1;
                }
                if(!vis[nx][ny]){
                    check.push_back({nx, ny});
                    sum += board[nx][ny];
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    int num = sum / check.size();
    for(int i = 0; i < check.size(); i++)
        board[check[i].X][check[i].Y] = num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int time = 0;
    while(true) {
        flag = false;
        clearVisit();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j]) bfs(i, j);
        if(!flag) {
            cout << time << '\n';
            break;
        }
        time++;
    }
    
    return 0;
}
