//
//  21611.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/30/23.
//

/*
 [Input]
 7 1
 0 0 0 0 0 0 0
 3 2 1 3 2 3 0
 2 1 2 1 2 1 0
 2 1 1 0 2 1 1
 3 3 2 3 2 1 2
 3 3 3 1 3 3 2
 2 3 2 2 3 2 3
 2 2
 [Output]
 28
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Gold 1
// Timer: 2h
// Url: https://www.acmicpc.net/problem/21611

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> board;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int marbleDir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void blizzard(int dir, int s) {
    int x = n / 2, y = n / 2;
    while(s--) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) break;
        board[nx * n + ny] = 0;
        x = nx;
        y = ny;
    }
}

void moveMarble() {
    queue<int> tmp;
    int x = n / 2, y = n / 2;
    int cnt = 0;
    for(int dir = 0; y >= 0; dir++) {
        dir %= 4;
        if(dir % 2 == 0) cnt++;
        for(int i = 0; i < cnt; i++) {
            x += marbleDir[dir][0];
            y += marbleDir[dir][1];
            if(board[x * n + y] == 0) continue;
            tmp.push(board[x * n + y]);
            board[x * n + y] = 0;
        }
    }
    x = n / 2;
    y = n / 2;
    cnt = 0;
    for(int dir = 0; y >= 0; dir++) {
        dir %= 4;
        if(dir % 2 == 0) cnt++;
        for(int i = 0; i < cnt; i++) {
            x += marbleDir[dir][0];
            y += marbleDir[dir][1];
            if(tmp.empty()) return;
            board[x * n + y] = tmp.front();
            tmp.pop();
        }
    }
}

int bomb() {
    int ans = 0;

    while(1) {
        int x = n / 2, y = n / 2;
        int cnt = 0;
        int before = 0;
        vector<pair<int, int>> pos;
        bool isEnd = true;

        for(int dir = 0; y >= 0; dir++) {
            dir %= 4;
            if(dir % 2 == 0) cnt++;
            for(int i = 0; i < cnt; i++) {
                x += marbleDir[dir][0];
                y += marbleDir[dir][1];
                if(board[x * n + y] == before) pos.push_back({x, y});
                else {
                    if(pos.size() < 4) {
                        pos.clear();
                        before = board[x * n + y];
                        pos.push_back({x, y});
                    } else {
                        isEnd = false;
                        ans += before * pos.size();
                        for(auto p: pos) board[p.first * n + p.second] = 0;
                        pos.clear();
                        before = board[x * n + y];
                        pos.push_back({x, y});
                    }
                }
            }
        }
        if(isEnd) return ans;
        else moveMarble();
    }
}

void change() {
    queue<int> tmp;
    int x = n / 2, y = n / 2;
    int cnt = 0;
    int A = 0, B = 0;
    for(int dir = 0; y >= 0; dir++) {
        dir %= 4;
        if(dir % 2 == 0) cnt++;
        for(int i = 0; i < cnt; i++) {
            x += marbleDir[dir][0];
            y += marbleDir[dir][1];
            if(board[x * n + y] == B) A++;
            else {
                if(B != 0) {
                    tmp.push(A);
                    tmp.push(B);
                }
                B = board[x * n + y];
                A = 1;
            }
        }
    }
    x = n / 2;
    y = n / 2;
    cnt = 0;
    for(int dir = 0; y >= 0; dir++) {
        dir %= 4;
        if(dir % 2 == 0) cnt++;
        for(int i = 0; i < cnt; i++) {
            x += marbleDir[dir][0];
            y += marbleDir[dir][1];
            if(y < 0) return;
            if(tmp.empty()) board[x * n + y] = 0;
            else {
                board[x * n + y] = tmp.front();
                tmp.pop();
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int ans = 0;
    cin >> n >> m;
    board.resize(n * n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            board[i * n + j] = x;
        }
    }
    while(m--) {
        int d, s; cin >> d >> s;
        blizzard(--d, s);
        moveMarble();
        ans += bomb();
        change();
    }
    cout << ans;

	return 0;
}
