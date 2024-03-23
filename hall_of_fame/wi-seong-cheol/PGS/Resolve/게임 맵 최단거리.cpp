//
//  게임 맵 최단거리.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10000
// 난이도: Level 3
// Timer: 7m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
int n, m;
int dist[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int solve(const vector<vector<int>>& board) {
    queue<Point> Q;
    dist[0][0] = 1;
    Q.push({0, 0});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur.x == n - 1 && cur.y == m - 1) {
            return dist[cur.x][cur.y];
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 0) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({nx, ny});
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps) {
    n = int(maps.size());
    m = int(maps[0].size());
    memset(dist, -1, sizeof(dist));
    int answer = solve(maps);
    return answer;
}
