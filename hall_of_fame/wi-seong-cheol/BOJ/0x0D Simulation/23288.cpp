//
//  23288.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/2/24.
//

/*
 [Input]
 4 5 1
 4 1 2 3 3
 6 1 1 3 3
 5 6 1 3 2
 5 5 6 5 5
 [Output]
 4
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 64,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/23288

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, k;
int board[21][21];
int dir;                    // 동 남 서 북
int cur_r = 1, cur_c = 1;   // 현 위치
int dice[6] = {1, 2, 3, 4, 5, 6};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }

void next_dir() {
    int dice_bottom = dice[5];
    if(board[cur_r][cur_c] < dice_bottom)
        dir = (dir + 1) % 4;
    else if(board[cur_r][cur_c] > dice_bottom)
        dir = (dir + 3) % 4;

    if(OOB(cur_r + dx[dir], cur_c + dy[dir]))
        dir = (dir + 2) % 4;
}

void move() {
    int tmp[6];
    copy(begin(dice), end(dice), begin(tmp));

    if (dir == 0) {  // 동
        dice[0] = tmp[3];
        dice[2] = tmp[0];
        dice[5] = tmp[2];
        dice[3] = tmp[5];
    } else if (dir == 1) {  // 남
        dice[0] = tmp[1];
        dice[4] = tmp[0];
        dice[5] = tmp[4];
        dice[1] = tmp[5];
    } else if (dir == 2) {  // 서
        dice[0] = tmp[2];
        dice[2] = tmp[5];
        dice[5] = tmp[3];
        dice[3] = tmp[0];
    } else if (dir == 3) {  // 북
        dice[0] = tmp[4];
        dice[4] = tmp[5];
        dice[5] = tmp[1];
        dice[1] = tmp[0];
    }

    cur_r += dx[dir];
    cur_c += dy[dir];
}

void get_score() {
    int tile = 1;
    bool vis[22][22] = {};
    queue<pair<int, int>> Q;
    Q.push({cur_r, cur_c});
    vis[cur_r][cur_c] = 1;

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nxt_r = cur.X + dx[dir];
            int nxt_c = cur.Y + dy[dir];
            if(OOB(nxt_r, nxt_c) || vis[nxt_r][nxt_c]) continue;
            if(board[nxt_r][nxt_c] != board[cur_r][cur_c]) continue;
            Q.push({nxt_r, nxt_c});
            vis[nxt_r][nxt_c] = 1;
            tile++;
        }
    }

    ans += tile * board[cur_r][cur_c];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    while(k--) {
        move();
        get_score();
        next_dir();
    }
    cout << ans;

    return 0;
}
