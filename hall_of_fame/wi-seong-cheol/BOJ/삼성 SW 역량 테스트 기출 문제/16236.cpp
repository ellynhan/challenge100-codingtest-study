//
//  16236.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 6
 5 4 3 2 3 4
 4 3 2 3 4 5
 3 2 9 5 6 6
 2 1 2 3 4 5
 3 2 1 6 5 4
 6 6 6 6 6 6
 [Output]
 60
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 160,000
// 난이도: Gold 3
// Timer: 19m
// Url: https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define X first
#define Y second
struct Point {
    int x, y;
};
int n, t;
int board[21][21];
int shark_size = 2;
int eatCount;
int shark_x, shark_y;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

vector<pair<Point, int>> findFish() {
    vector<pair<Point, int>> fish;
    queue<Point> Q;
    int dist[21][21];
    Q.push({shark_x, shark_y});
    memset(dist, -1, sizeof(dist));
    dist[shark_x][shark_y] = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] > shark_size) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({nx, ny});
            if(board[nx][ny] != 0 && board[nx][ny] < shark_size) {
                fish.push_back({{nx, ny}, dist[nx][ny]});
            }
        }
    }

    return fish;
}

bool cmp(const pair<Point, int>& a, const pair<Point, int>& b) {
    if(a.Y == b.Y) {
        if(a.X.x == b.X.x) {
            return a.X.y < b.X.y;
        }
        return a.X.x < b.X.x;
    }
    return a.Y < b.Y;
}

void eat(vector<pair<Point, int>>& fish) {
    sort(fish.begin(), fish.end(), cmp);
    Point p = fish[0].X;
    t += fish[0].Y;
    eatCount++;
    board[p.x][p.y] = 0;
    board[shark_x][shark_y] = 0;
    shark_x = p.x;
    shark_y = p.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark_x = i;
                shark_y = j;
                board[i][j] = 0;
            }
        }
    }

    while(true) {
        vector<pair<Point, int>> fish = findFish();
        if(fish.empty()) break;
        eat(fish);
        if(eatCount == shark_size) {
            shark_size++;
            eatCount = 0;
        }
    }
    cout << t;

	return 0;
}
