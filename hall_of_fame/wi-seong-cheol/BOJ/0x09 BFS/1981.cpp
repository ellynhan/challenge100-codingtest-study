//
//  1981.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/3/24.
//

/*
 [Input]
 5
 1 1 3 6 8
 1 2 2 5 5
 4 4 0 3 3
 8 0 2 3 4
 4 3 0 2 1
 [Output]
 2
 */
// 시간복잡도: O(n^2 * logn)
// 최악시간: 20,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1981

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 101
#define X first
#define Y second
int n;
int board[MAX][MAX];
int mn, mx;
bool vis[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool bfs(int k) {
    queue<pair<int, int>> Q;

    for(int i = mn; i <= mx; i++) {
        if(board[0][0] < i || board[0][0] > i + k) continue;
        Q.push({0, 0});
        memset(vis, false, sizeof(vis));
        vis[0][0] = true;

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if(cur.X == n - 1 && cur.Y == n - 1) return true;
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny) || board[nx][ny] < i || board[nx][ny] > i + k) continue;
                if(vis[nx][ny]) continue;
                Q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            mn = min(mn, board[i][j]);
            mx = max(mx, board[i][j]);
        }
    }

    int ans = 0;
    int lo = 0, hi = mx - mn;
    while(lo <= hi) {
        int mid = (lo + hi + 1) / 2;

        if(bfs(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;

	return 0;
}
