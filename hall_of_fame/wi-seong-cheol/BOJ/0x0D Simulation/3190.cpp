//
//  3190.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 6
 3
 3 4
 2 5
 5 3
 3
 3 D
 15 L
 17 D
 [Output]
 9
 */
// 시간복잡도: O(n * n)
// 최악시간: 10,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3190

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, k, l, c;
char d;
int second;
int board[101][101];
deque<pair<int, int>> dq;
queue<pair<int, char>> switchDir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 1 || x > n || y < 1 || y > n; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        board[x][y] = 2;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> c >> d;
        switchDir.push({c, d});
    }
    dq.push_front({1, 1});
    int dir = 1;
    while(1) {
        dir %= 4;

        auto cur = dq.front();
        board[cur.X][cur.Y] = 1;
        second++;

        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] == 1) break;

        if(board[nx][ny] != 2) {
            auto tail = dq.back();
            board[tail.X][tail.Y] = 0;
            dq.pop_back();
        }

        auto sd = switchDir.front();
        if(sd.X == second){
            if(sd.Y == 'L') dir += 1;
            else if(sd.Y == 'D') dir += 3;
            switchDir.pop();
        }
        dq.push_front({nx, ny});
    }
    cout << second;
    
    return 0;
}
