//
//  16234.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 4 10 50
 10 100 20 90
 80 100 60 70
 70 20 30 40
 50 20 100 10
 [Output]
 3
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 4
// Timer: 14m
// Url: https://www.acmicpc.net/problem/16234

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
int n, L, R;
int board[51][51];
bool vis[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool isCheck(int x, int y, int nx, int ny) {
    int diff = abs(board[x][y] - board[nx][ny]);
    return L <= diff && diff <= R;
}

vector<Point> bfs(int x, int y) {
    vector<Point> ret;
    queue<Point> Q;
    Q.push({x, y});
    vis[x][y] = true;
    ret.push_back({x, y});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(OOB(nx, ny) || !isCheck(cur.x, cur.y, nx, ny)) continue;
            if(vis[nx][ny]) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
            ret.push_back({nx, ny});
        }
    }

    return ret;
}

void movePeople(const vector<Point>& v) {
    int sum = 0;
    for(auto p: v) {
        sum += board[p.x][p.y];
    }
    int avg = sum / int(v.size());
    for(auto p: v) {
        board[p.x][p.y] = avg;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> L >> R;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    while(true) {
        bool flag = false;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j]) continue;
                auto v = bfs(i, j);
                if(v.size() > 1) {
                    flag = true;
                    movePeople(v);
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt;

	return 0;
}
