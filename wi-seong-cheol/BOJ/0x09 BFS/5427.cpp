//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 40
// Url: https://www.acmicpc.net/problem/5427

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int SIZE = 1001;
int n, m;
string board[SIZE];
int dist1[SIZE][SIZE];
int dist2[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> m >> n;
        bool isClear = false;
        queue<pair<int, int>> Q1, Q2;
        for(int i = 0; i < n; i++) {
            fill(dist1[i], dist1[i] + m, 0);
            fill(dist2[i], dist2[i] + m, 0);
            cin >> board[i];
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '*') {
                    Q1.push({i, j});
                    dist1[i][j] = 1;
                } else if(board[i][j] == '@') {
                    Q2.push({i, j});
                    dist2[i][j] = 1;
                }
            }
        }
        
        while(!Q1.empty()) {
            auto cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny) || dist1[nx][ny] || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx,ny});
            }
        }
        
        while(!Q2.empty() && (!isClear)) {
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny)) {
                    cout << dist2[cur.X][cur.Y] << "\n";
                    isClear = true;
                    break;
                }
                if(dist2[nx][ny] || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] != 0 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
                                
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
        }
        if(!isClear) cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
