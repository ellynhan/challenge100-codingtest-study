//
//  블록 이동하기.cpp
//  main
//
//  Created by wi_seong on 2/12/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Level 3
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/60063

#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int n;
int vis[101][101][4];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = int(board.size());
    queue<tuple<int,int,int,int>> q;

    q.push({0, 0, 0, 1});
    q.push({0, 0, 1, 3});
    vis[0][0][1] = vis[0][1][3] = 1;

    while(!q.empty()) {
        auto [cnt, y1, x1, dir] = q.front(); q.pop();

        int y2 = y1 + dy[dir];
        int x2 = x1 + dx[dir];

        if((y1 == n - 1 && x1 == n - 1) || (y2 == n - 1 && x2 == n - 1)) {
            return cnt;
        }

        for(int d=0; d<4; ++d) {
            int ny1 = y1 + dy[d];
            int nx1 = x1 + dx[d];
            int ny2 = y2 + dy[d];
            int nx2 = x2 + dx[d];

            if(OOB(ny1, nx1) || OOB(ny2, nx2)) continue;
            if(board[ny1][nx1] || board[ny2][nx2]) continue;

            if(!vis[ny1][nx1][dir]) {
                vis[ny1][nx1][dir] = 1;
                q.push({cnt + 1, ny1, nx1, dir});
            }
            if(!vis[ny2][nx2][(dir+2)%4]) {
                vis[ny2][nx2][(dir+2)%4] = 1;
                q.push({cnt + 1, ny2, nx2, (dir + 2) % 4});
            }

            if((dir + 1) % 2 == d % 2) {
                if(!vis[y1][x1][d]) {
                    vis[y1][x1][d] = 1;
                    q.push({cnt + 1, y1, x1, d});
                }
                if(!vis[y2][x2][(dir+2)%4]) {
                    vis[y2][x2][(dir+2)%4] = 1;
                    q.push({cnt + 1, y2, x2, (dir + 2) % 4});
                }
            }
        }
    }


    return answer;
}
