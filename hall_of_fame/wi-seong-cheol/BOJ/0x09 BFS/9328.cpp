//
//  9328.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 3
 5 17
 *****************
 .............**$*
 *B*A*P*C**X*Y*.X.
 *y*x*a*p**$*$**$*
 *****************
 cz
 5 11
 *.*********
 *...*...*x*
 *X*.*.*.*.*
 *$*...*...*
 ***********
 0
 7 7
 *ABCDE*
 X.....F
 W.$$$.G
 V.$$$.H
 U.$$$.J
 T.....K
 *SQPML*
 irony
 [Output]
 3
 1
 0
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/9328

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int w, h;
string key;
int keys[26];
char board[102][102];
bool vis[102][102];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x > h+1 || y < 0 || y > w+1; }

void init() {
    fill(keys, keys + 26, 0);
    for(int i = 0; i <= h+1; i++) {
        fill(vis[i], vis[i]+w+2, false);
        fill(board[i], board[i]+w+2, 0);
    }
}

int bfs() {
    int ans = 0;
    queue<pair<int, int>> Q;
    queue<pair<int, int>> door[26];
    Q.push({0, 0});
    vis[0][0] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == '*') continue;
            vis[nx][ny] = true;
            if('a' <= board[nx][ny] && board[nx][ny] <= 'z') {
                int k = board[nx][ny] - 'a';
                keys[k] = 1;
                while(!door[k].empty()) {
                    auto ndoor = door[k].front(); door[k].pop();
                    Q.push({ndoor.X, ndoor.Y});
                }
            } else if('A' <= board[nx][ny] && board[nx][ny] <= 'Z') {
                int k = board[nx][ny] - 'A';
                if(!keys[k]) {
                    door[k].push({nx, ny});
                    continue;
                }
            } else if (board[nx][ny] == '$') ans++;
            Q.push({nx, ny});
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> h >> w;
        init();
        for(int i  = 1; i <= h; i++)
            for(int j = 1; j <= w; j++) cin >>
                board[i][j];
        cin >> key;
        if(key != "0") {
            for(auto k : key) keys[k - 'a'] = 1;
        }
        cout << bfs() << '\n';
    }

    return 0;
}
