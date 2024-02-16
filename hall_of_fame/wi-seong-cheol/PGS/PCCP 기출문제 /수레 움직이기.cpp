//
//  수레 움직이기.cpp
//  main
//
//  Created by wi_seong on 2/12/24.
//

// 시간복잡도: O(16 ^ n)
// 최악시간: 256
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/250134

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;
struct Point {
    int x, y;
};
Point bStartPoint, rStartPoint, bEndPoint, rEndPoint;
int answer;
int n, m;
bool rVis[4][4], bVis[4][4];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

bool isExit(Point b, Point r) {
    return b.x == bEndPoint.x && b.y == bEndPoint.y && r.x == rEndPoint.x && r.y == rEndPoint.y;
}

void solve(const vector<vector<int>>& maze, Point b, Point r, int turn) {
    if(isExit(b, r)) {
        answer = min(answer, turn);
        return;
    }

    for(int dir1 = 0; dir1 < 4; dir1++) {
        int nx1, ny1;
        if(b.x == bEndPoint.x && b.y == bEndPoint.y) {
            nx1 = b.x;
            ny1 = b.y;
        } else {
            nx1 = b.x + dx[dir1];
            ny1 = b.y + dy[dir1];
            if(bVis[nx1][ny1]) continue;
        }
        if(OOB(nx1, ny1) || maze[nx1][ny1] == 5) continue;

        for(int dir2 = 0; dir2 < 4; dir2++) {
            int nx2, ny2;
            if(r.x == rEndPoint.x && r.y == rEndPoint.y) {
                nx2 = r.x;
                ny2 = r.y;
            } else {
                nx2 = r.x + dx[dir2];
                ny2 = r.y + dy[dir2];
                if(rVis[nx2][ny2]) continue;
            }
            if(OOB(nx2, ny2) || maze[nx2][ny2] == 5) continue;
            if(nx1 == nx2 && ny1 == ny2) continue;
            if(nx1 == r.x && ny1 == r.y && nx2 == b.x && ny2 == b.y) continue;

            bVis[nx1][ny1] = rVis[nx2][ny2] = true;
            solve(maze, {nx1, ny1}, {nx2, ny2}, turn + 1);
            bVis[nx1][ny1] = rVis[nx2][ny2] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    answer = INF;
    n = int(maze.size());
    m = int(maze[0].size());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 0 || maze[i][j] == 5) continue;
            if(maze[i][j] == 1) rStartPoint = {i, j};
            else if(maze[i][j] == 2) bStartPoint = {i, j};
            else if(maze[i][j] == 3) rEndPoint = {i, j};
            else bEndPoint = {i, j};
        }
    }

    bVis[bStartPoint.x][bStartPoint.y] = true;
    rVis[rStartPoint.x][rStartPoint.y] = true;
    solve(maze, bStartPoint, rStartPoint, 0);

    return answer == INF ? 0 : answer;
}
