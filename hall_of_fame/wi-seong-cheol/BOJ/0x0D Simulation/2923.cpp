//
//  2923.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 8 8
 ........
 ........
 ...x.xx.
 ...xxx..
 ..xxx...
 ..x.xxx.
 ..x...x.
 .xxx..x.
 5
 6 6 4 3 1
 [Output]
 ........
 ........
 ........
 ........
 .....x..
 ..xxxx..
 ..xxx.x.
 ..xxxxx.
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 1
// Timer: 2h
// Url: https://www.acmicpc.net/problem/2923

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
#define X first
#define Y second
#define INF 987654321
int r, c, n;
bool vis[101][101] = { 0 };
string board[101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0 ,0};

bool OOB(int x, int y) { return x < 0 || x > r || y < 0 || y >= c; }

void attack(int turn, int height) {
    if(turn == 0) {
        for(int j = 0; j < c; j++) {
            if(board[r - height][j] == 'x') {
                board[r - height][j] = '.';
                return;
            }
        }
    } else {
        for(int j = c - 1; j >= 0; j--) {
            if(board[r - height][j] == 'x') {
                board[r - height][j] = '.';
                return;
            }
        }
    }
}

bool isCluster() {
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> Q;

    Q.push({r, 0});
    vis[r][0] = true;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == '.') continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(!vis[i][j] && board[i][j] == 'x')
                return true;

    return false;
}

void gravity() {
    int cnt = r;

    for(int j = 0; j < c; j++) {
        for(int i = r; i > 0; i--) {
            if(board[i][j] != 'x' || !vis[i][j]) continue;
            int h = 0;
            for(int k = i - 1; k >= 0; k--) {
                if(board[k][j] == 'x') {
                    if(!vis[k][j])
                        cnt = min(cnt, h);
                    break;
                }
                else h++;
            }
        }
    }

    for(int j = 0; j < c; j++)
        for(int i = r - 1; i >= 0; i--)
            if(!vis[i][j] && board[i][j] == 'x') {
                board[i + cnt][j] = 'x';
                board[i][j] = '.';
            }
}

void print() {
    for(int i = 0; i < r; i++) {
        cout << board[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < c; i++) {
        board[r].push_back('x');
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int height; cin >> height;
        attack(i % 2, height);
        if(isCluster()) {
            gravity();
        }
    }
    print();

	return 0;
}
