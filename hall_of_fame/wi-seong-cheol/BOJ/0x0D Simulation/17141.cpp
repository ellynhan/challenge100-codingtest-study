//
//  17141.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 3
 2 0 0 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 0 1 0 0
 0 1 0 0 0 0 0
 0 0 0 2 0 1 1
 0 1 0 0 0 0 0
 2 1 0 0 0 0 2
 [Output]
 5
 */
// 시간복잡도: O((2 ^ m) * (n * n))
// 최악시간: 2,560,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17141

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7f;
int ans = INF;
int n, m;
int board[51][51];
int dist[51][51];
vector<pair<int, int>> v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs(queue<pair<int, int>>& Q) {
    int mx = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        mx = max(mx, dist[cur.X][cur.Y]);
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] >= 0) continue;
            if(board[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    
    return mx;
}

void init() {
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                v.push_back({i, j});
                board[i][j] = 0;
            }
        }
    
    vector<int> brute(v.size());
    for(int i = m; i < v.size(); i++) brute[i] = 1;
    
    do {
        init();
        queue<pair<int, int>> virus;
        
        for(int i = 0; i < brute.size(); i++)
            if(!brute[i]) {
                virus.push(v[i]);
                dist[v[i].X][v[i].Y] = 0;
            }
        
        int t = bfs(virus);
        
        bool flag = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 0 && dist[i][j] == -1)
                    flag = false;
        
        if(flag) ans = min(ans, t);
    } while(next_permutation(brute.begin(), brute.end()));
    
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
