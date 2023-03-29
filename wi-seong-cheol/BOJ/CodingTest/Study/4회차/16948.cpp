//
//  16948.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 6
 5 1 0 5
 [Output]
 -1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/16948

#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;
#define X first
#define Y second
int n;
int r1, c1, r2, c2;
int dist[201][201];
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs() {
    queue<pair<int, int>> Q;
    Q.push({r1, c1});
    dist[r1][c1] = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur.X == r2 && cur.Y == c2) break;
        for(int dir = 0; dir < 6; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    
    return dist[r2][c2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dist, -1, sizeof(dist));
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << bfs();
    
    return 0;
}
