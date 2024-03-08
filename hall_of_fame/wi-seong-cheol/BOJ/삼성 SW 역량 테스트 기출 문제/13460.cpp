//
//  13460.cpp
//  main
//
//  Created by wi_seong on 3/4/24.
//

/*
 [Input]
 7 7
 #######
 #...RB#
 #.#####
 #.....#
 #####.#
 #O....#
 #######
 [Output]
 5
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 100,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13460

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
int n, m;
string board[11];
int dist[11][11][11][11];
Point r, b;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

Point move(int x, int y, int dir) {
    while(true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(board[nx][ny] != '.') break;
        x = nx;
        y = ny;
    }
    return {x, y};
}

bool goal(Point p, int dir) {
    return board[p.x + dx[dir]][p.y + dy[dir]] == 'O';
}

int solve() {
    queue<pair<Point, Point>> Q;
    dist[r.x][r.y][b.x][b.y] = 0;
    Q.push({r, b});

    while(!Q.empty()) {
        auto [R, B] = Q.front(); Q.pop();
        if(dist[R.x][R.y][B.x][B.y] >= 10) break;

        for(int dir = 0; dir < 4; dir++) {
            Point nR = move(R.x, R.y, dir);
            Point nB = move(B.x, B.y, dir);
            if(goal(nB, dir)) continue;
            if(goal(nR, dir)) return dist[R.x][R.y][B.x][B.y] + 1;

            if(nR.x == nB.x && nR.y == nB.y) {
                if(dir == 0) // 위쪽
                    R.y < B.y ? nR.y-- : nB.y--;
                else if(dir == 1) // 오른쪽
                    R.x < B.x ? nR.x-- : nB.x--;
                else if(dir == 2) // 아래쪽
                    R.y > B.y ? nR.y++ : nB.y++;
                else // 왼쪽
                    R.x > B.x ? nR.x++ : nB.x++;
            }
            if(dist[nR.x][nR.y][nB.x][nB.y] != -1) continue;
            dist[nR.x][nR.y][nB.x][nB.y] = dist[R.x][R.y][B.x][B.y] + 1;
            Q.push({nR, nB});
        }
    }

    return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(dist, -1, sizeof(dist));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                r = {i, j};
                board[i][j] = '.';
            } else if(board[i][j] == 'B') {
                b = {i, j};
                board[i][j] = '.';
            }
        }
    }
    cout << solve();

	return 0;
}
