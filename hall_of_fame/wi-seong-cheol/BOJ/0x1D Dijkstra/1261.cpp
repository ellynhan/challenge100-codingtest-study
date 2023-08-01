//
//  1261.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 3
 011
 111
 110
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1261

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
int d[101][101];
int board[101][101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }

int solve() {
    d[1][1] = 0;
    pq.push({d[1][1], 1, 1});
    
    while(!pq.empty()) {
        int w, x, y;
        tie(w, x, y) = pq.top(); pq.pop();
        if(d[x][y] != w) continue;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            int nw = w + board[nx][ny];
            if(d[nx][ny] <= nw) continue;
            d[nx][ny] = nw;
            pq.push({nw, nx, ny});
        }
    }
    
    return d[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++) {
        string str; cin >> str;
        for(int j = 1; j <= m; j++)
            board[i][j] = str[j - 1] - '0';
    }
    for(int i = 1; i <= n; i++)
        fill(d[i] + 1, d[i] + m + 1, INF);
    cout << solve();
    
    return 0;
}
