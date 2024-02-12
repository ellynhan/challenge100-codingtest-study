//
//  지형 이동.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 90,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/62050

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
struct Point {
    int x, y;
};
const int MXN = 301;
int n, h;
bool vis[MXN][MXN];
vector<vector<int>> board;
vector<tuple<int, int, int>> edge;
vector<int> p(MXN * MXN, -1);
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void marking(const vector<vector<int>>& land, int idx, int x, int y) {
    queue<Point> Q;
    Q.push({x, y});
    board[x][y] = idx;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(OOB(nx, ny) || board[nx][ny] != 0) continue;
            if(abs(land[cur.x][cur.y] - land[nx][ny]) > h) continue;
            board[nx][ny] = idx;
            Q.push({nx, ny});
        }
    }
}

void findEdge(const vector<vector<int>>& land, int x, int y) {
    queue<Point> Q;
    Q.push({x, y});
    vis[x][y] = true;
    int idx = board[x][y];

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] != idx) {
                int w = abs(land[cur.x][cur.y] - land[nx][ny]);
                edge.push_back({w, idx, board[nx][ny]});
                continue;
            }
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int isDiffGroup(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    n = int(land.size());
    h = height;

    board.resize(n);
    for(int i = 0; i < n; i++) {
        board[i].resize(n);
    }

    int idx = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] != 0) continue;
            marking(land, idx++, i, j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j]) continue;
            findEdge(land, i, j);
        }
    }

    sort(edge.begin(), edge.end());

    int w, a, b;
    int cnt = 0;
    for(auto e: edge) {
        tie(w, a, b) = e;
        if(!isDiffGroup(a, b)) continue;
        cnt++;
        answer += w;
        if(cnt == idx - 1) break;
    }

    return answer;
}
