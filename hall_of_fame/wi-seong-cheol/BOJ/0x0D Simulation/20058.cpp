//
//  20058.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/29/23.
//

/*
 [Input]
 3 1
 1 2 3 4 5 6 7 8
 8 7 6 5 4 3 2 1
 1 2 3 4 5 6 7 8
 8 7 6 5 4 3 2 1
 1 2 3 4 5 6 7 8
 8 7 6 5 4 3 2 1
 1 2 3 4 5 6 7 8
 8 7 6 5 4 3 2 1
 1
 [Output]
 284
 64
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 262,144
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20058

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, q;
int board[64][64];
bool vis[64][64];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y, int size) { return x < 0 || x >= size || y < 0 || y >= size; }

int bfs(int x, int y) {
    int size = 1 << n;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    int cnt = 1;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny, size) || vis[nx][ny] || board[nx][ny] == 0) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
            cnt++;
        }
    }

    return cnt;
}

void rotate(int i, int j, int len) {
    int tmp[64][64];
    for(int x = 0; x < len; x++) {
        for(int y = 0; y < len; y++) {
            tmp[x][y] = board[i + len - 1 - y][j + x];
        }
    }
    for(int x = 0; x < len; x++) {
        for(int y = 0; y < len; y++) {
            board[i + x][j + y] = tmp[x][y];
        }
    }
}

void melting() {
    queue<pair<int, int>> Q;
    int size = 1 << n;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(OOB(nx, ny, size) || board[nx][ny] == 0) continue;
                cnt++;
            }
            if(cnt >= 3) continue;
            Q.push({i, j});
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int x = cur.X;
        int y = cur.Y;
        board[x][y] = max(0, board[x][y] - 1);
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> q;
    int size = 1 << n;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }
    for(int t = 0; t < q; t++) {
        int x; cin >> x;
        int len = 1 << x;
        for(int i = 0; i < size; i += len) {
            for(int j = 0; j < size; j += len) {
                rotate(i, j, len);
            }
        }
        melting();
    }

    int sum = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            sum += board[i][j];
        }
    }
    cout << sum << '\n';

    int mx = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            mx = max(mx, bfs(i, j));
        }
    }
    cout << mx;

	return 0;
}
