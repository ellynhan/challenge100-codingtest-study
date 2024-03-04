//
//  리코쳇 로봇.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/169199

#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
int n, m;
Point S, E;
int dist[4][101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y  < 0 || y >= m; }

int bfs(const vector<string>& board) {
    queue<pair<Point, int>> Q;
    Q.push({{S.x, S.y}, 0});
    dist[0][S.x][S.y] = dist[1][S.x][S.y] = dist[2][S.x][S.y] = dist[3][S.x][S.y] = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        Point p = cur.first;
        int d = cur.second;

        if(p.x == E.x && p.y == E.y) return dist[d][p.x][p.y];

        for(int dir = 0; dir < 4; dir++) {
            int nx = p.x;
            int ny = p.y;
            bool flag = false;
            while(true) {
                int tmpX = nx + dx[dir];
                int tmpY = ny + dy[dir];
                if(OOB(tmpX, tmpY)) break;
                if(board[tmpX][tmpY] == 'D') break;
                if(dist[dir][tmpX][tmpY] != -1) {
                    flag = true;
                    break;
                }
                nx = tmpX;
                ny = tmpY;
                dist[dir][nx][ny] = dist[d][p.x][p.y] + 1;
            }
            if(flag) continue;
            if(nx == p.x && ny == p.y) continue;
            Q.push({{nx, ny}, dir});
        }
    }

    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    n = int(board.size());
    m = int(board[0].size());
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') S = {i, j};
            else if(board[i][j] == 'G') E = {i, j};
        }
    }

    answer = bfs(board);

    return answer;
}
