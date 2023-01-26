//
//  14502.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 7
 2 0 0 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 0 1 0 0
 0 1 0 0 0 0 0
 0 0 0 0 0 1 1
 0 1 0 0 0 0 0
 0 1 0 0 0 0 0
 [Output]
 27
 */
// 시간복잡도: O(n * m * (2^n))
// 최악시간: 16,384
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14502

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, m, ans;
int board[9][9];
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(const int lab[][9]) {
    queue<pair<int, int>> Q;
    bool vis[n][m];
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + m, false);
    for(int i = 0; i < virus.size(); i++) {
        Q.push({virus[i].X, virus[i].Y});
        vis[virus[i].X][virus[i].Y] = true;
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(lab[nx][ny] != 0) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(lab[i][j] == 0 && !vis[i][j])
                cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0)
                blank.push_back({i, j});
            else if(board[i][j] == 2)
                virus.push_back({i, j});
        }
    vector<int> brute(blank.size());
    fill(brute.begin() + blank.size() - 3, brute.end(), 1);
    do {
        int lab[n][9];
        for(int i = 0; i < n; i++)
            copy(board[i], board[i] + m, lab[i]);
        for(int i = 0; i < blank.size(); i++) {
            if(brute[i] == 1)
                lab[blank[i].X][blank[i].Y] = 1;
        }
        ans = max(ans, bfs(lab));
    } while(next_permutation(brute.begin(), brute.end()));
    
    cout << ans;
    
    return 0;
}
