//
//  17406.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 5 6 2
 1 2 3 2 5 6
 3 8 7 2 1 3
 8 2 3 1 4 5
 3 4 5 1 1 1
 9 3 2 1 4 3
 3 4 2
 4 2 1
 [Output]
 12
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17406

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 0x7f7f7f7f;
struct Turn_Info {
    int R, C, S;
};
int n, m, k, r, c, s;
int ans = INF;
vector<Turn_Info> v;
vector<int> order;
bool isused[6];
int board[51][51];
int cBoard[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int changeDirection(int cur) {
    if(cur == 0) return 3;
    else if(cur == 1) return 2;
    else if(cur == 2) return 0;
    else return 1;
}

void rotate(Turn_Info T) {
    int sx = T.R - T.S;
    int sy = T.C - T.S;
    int ex = T.R + T.S;
    int ey = T.C + T.S;

    int turn = (ex - sx) / 2;

    for(int i = 0; i < turn; i++) {
        int x = sx;
        int y = sy;
        int tmp = cBoard[x][y];
        int d = 2;

        while (1) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx == sx && ny == sy) {
                cBoard[x][y] = tmp;
                break;
            }

            if(sx <= nx && nx <= ex - i && sy <= ny &&  ny <= ey - i) {
                cBoard[x][y] = cBoard[nx][ny];
                x = nx;
                y = ny;
            } else {
                d = changeDirection(d);
            }
        }
        sx++;
        sy++;
    }
}

int calculate() {
    int ret = INF;

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= m; j++)
            sum += cBoard[i][j];
        ret = min(ret, sum);
    }

    return ret;
}

void copyBoard() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cBoard[i][j] = board[i][j];
}

void solve(int cnt) {
    if(cnt == k) {
        copyBoard();
        for (int i = 0; i < order.size(); i++) {
            int o = order[i];
            rotate(v[o]);
        }
        ans = min(ans, calculate());
        return;
    }

    for(int i = 0; i < v.size(); i++) {
        if(isused[i]) continue;
        isused[i] = true;
        order.push_back(i);
        solve(cnt + 1);
        order.pop_back();
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    for(int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }

    solve(0);

    cout << ans;

    return 0;
}
