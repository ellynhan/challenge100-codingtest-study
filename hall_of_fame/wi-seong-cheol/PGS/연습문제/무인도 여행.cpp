//
//  무인도 여행.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
bool vis[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int x, int y, const vector<string>& maps) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    int ret = maps[x][y] - '0';

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(maps[nx][ny] == 'X') continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
            ret += maps[nx][ny] - '0';
        }
    }

    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = int(maps.size());
    m = int(maps[0].size());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            if(maps[i][j] == 'X') continue;
            answer.push_back(bfs(i, j, maps));
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());

    return answer;
}
