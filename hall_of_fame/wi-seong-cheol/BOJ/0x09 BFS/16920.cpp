//
//  16920.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 4 4 2
 1 1
 1...
 ....
 ....
 ...2
 [Output]
 10 6
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16920

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, m, p;
int ans1, ans2;
char board[1001][1001];
int area[10];
int mov[10];
queue<tuple<int, int, int>> Q[10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs() {
    while (1) {
        bool isExtend = false;
        for(int i = 1; i <= p; i++) {
            queue<tuple<int, int, int>> nxtQ;
            while(!Q[i].empty()) {
                int x, y, step;
                tie(x, y, step) = Q[i].front(); Q[i].pop();
                if(step >= mov[i]) {
                    nxtQ.push({x, y, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(OOB(nx, ny) || board[nx][ny] != 1) continue;
                    Q[i].push({nx, ny, step + 1});
                    board[nx][ny] = 0;
                    area[i]++;
                    isExtend = true;
                }
            }
            Q[i] = nxtQ;
        }
        if(!isExtend) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> mov[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == '.') {
                board[i][j] = 1;
            } else if(c == '#') {
                board[i][j] = 0;
            } else {
                board[i][j] = 0;
                Q[c - '0'].push({i, j, 0});
                area[c - '0']++;
            }
        }
    }
    bfs();
    for(int i = 1; i <= p; i++)
        cout << area[i] << ' ';
    
    return 0;
}

