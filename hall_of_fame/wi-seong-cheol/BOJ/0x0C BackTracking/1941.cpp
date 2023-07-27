//
//  1941.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 YYYYY
 SYSYS
 YYYYY
 YSYYS
 YYYYY
 [Output]
 2
 */
// 시간복잡도: O(2^n)
// 최악시간: 33,554,432
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1941

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int ans;
char board[5][5];
bool isused[25];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool OOB(int x, int y) { return x < 0 || x >= 5 || y < 0 || y >= 5; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    fill(isused + 7, isused + 25, true);
    do {
        queue<pair<int, int>> Q;
        int dasom = 0;
        int adj = 0;
        bool isp7[5][5] = {};
        bool vis[5][5] = {};
        for(int i = 0; i < 25; i++) {
            if(!isused[i]) {
                int x = i / 5;
                int y = i % 5;
                isp7[x][y] = true;
                if(Q.empty()) {
                    Q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        while(!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            adj++;
            dasom += board[x][y] == 'S';
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OOB(nx, ny) || vis[nx][ny] || !isp7[nx][ny]) continue;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
        ans += (adj >= 7 && dasom >= 4);
    } while(next_permutation(isused, isused + 25));
    cout << ans;
    
    return 0;
}
