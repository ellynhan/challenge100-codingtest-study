//
//  미로 탈출.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
Point S, E, L;
int n, m;
int dist[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(Point start, Point arrive, const vector<string>& maps) {
    queue<Point> Q;
    Q.push(start);
    dist[start.x][start.y] = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        if(cur.x == arrive.x && cur.y == arrive.y) break;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(OOB(nx, ny) || maps[nx][ny] == 'X') continue;
            if(dist[nx][ny] != -1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
        }
    }

    return dist[arrive.x][arrive.y];
}

int solution(vector<string> maps) {
    int answer = 0;
    n = int(maps.size());
    m = int(maps[0].size());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] == 'S') S = {i, j};
            else if(maps[i][j] == 'E') E = {i, j};
            else if(maps[i][j] == 'L') L = {i, j};
        }
    }

    memset(dist, -1, sizeof(dist));
    int result = bfs(S, L, maps);
    if(result == -1) return {-1};
    answer += result;

    memset(dist, -1, sizeof(dist));
    result = bfs(L, E, maps);
    if(result == -1) return {-1};
    answer += result;

    return answer;
}
