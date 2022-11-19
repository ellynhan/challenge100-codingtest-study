//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 7
 0 0 0 0 0 0 0
 0 2 4 5 3 0 0
 0 3 0 2 5 2 0
 0 7 6 2 4 0 0
 0 0 0 0 0 0 0
 [Output]
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 90,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2573

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int SIZE = 301;
int n, m;
int board[SIZE][SIZE];
int ice[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void countIce(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(board[nx][ny] == 0) continue;
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

void melting() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) continue;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(!OOB(i, j) && board[nx][ny] == 0) {
                    ice[i][j] += 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board[i][j] = max(0, board[i][j] - ice[i][j]);
}

void init() {
    for(int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + m, false);
        fill(ice[i], ice[i] + m, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    int time = 0;
    while(1) {
        time++;
        init();
        melting();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] > 0 && !vis[i][j]) {
                    countIce(i, j);
                    cnt++;
                }
            }
        }
        
        if(cnt == 0) {
            time = 0;
            break;
        } else if(cnt == 1) continue;
        else break;
    }
    cout << time;
    
    return 0;
}
