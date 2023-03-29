//
//  17142.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 4
 2 0 2 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 2 1 0 0
 2 1 0 0 0 0 2
 0 0 0 2 0 1 1
 0 1 0 0 0 0 0
 2 1 0 0 2 0 2
 [Output]
 4
 */
// 시간복잡도: O((2 ^ m) * (n * n))
// 최악시간: 2,560,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17142

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7f;
int ans = INF;
int n, m, emptyCnt;
vector<pair<int, int>> v;
int board[51][51];
int dist[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs(queue<pair<int, int>>& Q) {
    int num = 0;
    int times = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            if(board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
            if(board[nx][ny] != 2){
                times = dist[nx][ny];
                num++;
            }
        }
    }
    
    if(emptyCnt == num) return times;
    return INF;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                v.push_back({i, j});
            else if(board[i][j] == 0)
                emptyCnt++;
        }
    
    vector<int> brute(v.size());
    fill(brute.begin() + m, brute.end(), 1);
    
    do {
        queue<pair<int, int>> virus;
        for(int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n, -1);
        for(int i = 0; i < brute.size(); i++)
            if(!brute[i]) {
                virus.push(v[i]);
                dist[v[i].X][v[i].Y] = 0;
            }
        ans = min(ans, bfs(virus));
    } while(next_permutation(brute.begin(), brute.end()));
    
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
