//
//  3184.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 6 6
 ...#..
 .##v#.
 #v.#.#
 #.o#.#
 .###.#
 ...###
 [Output]
 0 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 62,500
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/3184

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int r, c, sheep, wolf;
char board[251][251];
bool vis[251][251];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int a, int b) { return a < 0 || a >= r || b < 0 || b >= c; }

pair<int, int> bfs(int x, int y) {
    pair<int, int> ret = {0, 0};    // sheep, wolf
    if(board[x][y] == 'o') ret.X++;
    if(board[x][y] == 'v') ret.Y++;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == 'o') ret.X++;
            if(board[nx][ny] == 'v') ret.Y++;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        cin >> board[i];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!vis[i][j] && board[i][j] != '#') {
                auto res = bfs(i, j);
                if(res.X <= res.Y) {
                    wolf += res.Y;
                } else {
                    sheep += res.X;
                }
            }
        }
    }
    cout << sheep << ' ' << wolf;
    
    return 0;
}

