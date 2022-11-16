//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
 [Output]
 3
 7
 8
 9
 */
// 시간복잡도: O(n * n)
// 최악시간: 625
// 난이도: Silver 1
// Timer: 5m
// Url: https://www.acmicpc.net/problem/2667

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 26;
int n;
string board[SIZE];
bool vis[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<int> ans;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == '0') continue;
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
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '1' && !vis[i][j]) {
                ans.push_back(bfs(i, j));
            }
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    
    return 0;
}
