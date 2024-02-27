//
//  아이템 줍기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/4/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/87694

#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;
const int MXN = 111;
int board[MXN][MXN];
int dist[MXN][MXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int solve(int x, int y, int itemX, int itemY) {
    queue<tuple<int, int, int>> Q;
    Q.push({0, x, y});
    dist[x][y] = 0;

    while(!Q.empty()) {
        int isCorner, x, y;
        tie(isCorner, x, y) = Q.front(); Q.pop();
        if(x == itemX && y == itemY) return dist[itemX][itemY];
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(board[nx][ny] == 0 || board[nx][ny] > 2) continue;
            if(dist[nx][ny] != -1) continue;
            int val = (board[nx][ny] == 1);
            if(dir % 2 == 0) {
                int dir1 = 1;
                int nx1 = nx + dx[dir1];
                int ny1 = ny + dy[dir1];

                int dir2 = 3;
                int nx2 = nx + dx[dir2];
                int ny2 = ny + dy[dir2];

                if(board[nx1][ny1] == 0 || board[nx2][ny2] == 0)  {
                    Q.push({0, nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                } else if(!isCorner) {
                    Q.push({1, nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            } else {
                int dir1 = 0;
                int nx1 = nx + dx[dir1];
                int ny1 = ny + dy[dir1];

                int dir2 = 2;
                int nx2 = nx + dx[dir2];
                int ny2 = ny + dy[dir2];

                if(board[nx1][ny1] == 0 || board[nx2][ny2] == 0)  {
                    Q.push({0, nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                } else if(!isCorner) {
                    Q.push({1, nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(dist, -1, sizeof(dist));

    for(auto rect: rectangle) {
        for(int x = rect[0] * 2; x <= rect[2] * 2; x++) {
            for(int y = rect[1] * 2; y <= rect[3] * 2; y++) {
                board[x][y]++;
            }
        }
    }

    int answer = solve(characterX * 2, characterY * 2, itemX * 2, itemY * 2) / 2;

    return answer;
}
