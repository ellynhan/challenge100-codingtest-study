//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 7 3
 0 2 4 4
 1 1 2 5
 4 0 6 2
 [Output]
 3
 1 7 13
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 16m
// Url: https://www.acmicpc.net/problem/2583

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 101;
int n, m, k;
int board[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<int> ans;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    cnt++;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 1) continue;
            cnt++;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int a = n - y2; a < n - y1; a++) {
            for(int b = x1; b < x2; b++) {
                board[a][b] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 && !vis[i][j]) {
                ans.push_back(bfs(i, j));
            }
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
        
    
    return 0;
}
