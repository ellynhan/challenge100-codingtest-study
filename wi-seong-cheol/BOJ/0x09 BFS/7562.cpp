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
// 최악시간: 90,000
// 난이도: Silver 1
// Timer: 16m
// Url: https://www.acmicpc.net/problem/7562

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int SIZE = 301;
int n;
int board[SIZE][SIZE];
int dist[SIZE][SIZE];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int x1, y1, x2, y2;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[x][y] = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(dist[x2][y2] != -1) break;
        for(int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n + 1, -1);
        bfs(x1, y1);
        cout << dist[x2][y2] << '\n';
    }
    
    return 0;
}
