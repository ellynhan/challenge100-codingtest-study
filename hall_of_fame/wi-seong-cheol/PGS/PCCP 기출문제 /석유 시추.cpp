//
//  석유 시추.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/250136

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
int n, m;
int vis[501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int id, int x, int y, const vector<vector<int>>& board) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = id;
    int ret = 1;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 0) continue;
            if(vis[nx][ny] != -1) continue;
            Q.push({nx, ny});
            vis[nx][ny] = id;
            ret++;
        }
    }

    return ret;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    unordered_map<int, int> oil;
    n = int(land.size());
    m = int(land[0].size());
    int id = 0;
    memset(vis, -1, sizeof(vis));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] != -1 || land[i][j] == 0) continue;
            int cnt = bfs(id, i, j, land);
            oil[id++] = cnt;
        }
    }

    for(int j = 0; j < m; j++) {
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            if(vis[i][j] == -1) continue;
            s.insert(vis[i][j]);
        }

        int cnt = 0;
        for(int idx: s)
            cnt += oil[idx];
        answer = max(answer, cnt);
    }

    return answer;
}
