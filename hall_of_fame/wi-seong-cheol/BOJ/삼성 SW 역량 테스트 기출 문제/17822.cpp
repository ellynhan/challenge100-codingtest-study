//
//  17822.cpp
//  main
//
//  Created by wi_seong on 3/15/24.
//

/*
 [Input]
 4 4 3
 1 1 2 3
 5 2 4 2
 3 1 3 5
 2 1 3 2
 2 0 1
 3 1 3
 2 0 2
 [Output]
 22
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17822

#include <iostream>
#include <cstring>

using namespace std;
int n, m, t;
int board[51][51];
bool vis[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void rotate(int idx, int cnt) {
    int tmp[51];
    for(int i = 0; i < m; i++) {
        tmp[i] = board[idx - 1][(i + cnt) % m];
    }
    for(int i = 0; i < m; i++) {
        board[idx - 1][i] = tmp[i];
    }
}

void remove() {
    memset(vis, false, sizeof(vis));
    bool flag = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = (j + dy[dir] + m) % m;
                if(nx < 0 || nx >= n) continue;
                if(board[i][j] == -1 || board[i][j] != board[nx][ny]) continue;
                vis[i][j] = true;
                vis[nx][ny] = true;
                flag = false;
            }
        }
    }

    if(flag) {
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == -1) continue;
                sum += board[i][j];
                cnt++;
            }
        }
        double avg = double(sum) / double(cnt);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == -1) continue;
                if(double(board[i][j]) > avg) {
                    board[i][j]--;
                } else if(double(board[i][j]) < avg) {
                    board[i][j]++;
                }
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 1) {
                    board[i][j] = -1;
                }
            }
        }
    }
}

int calc() {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == -1) continue;
            ret += board[i][j];
        }
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while(t--) {
        int x, d, k;
        cin >> x >> d >> k;

        for(int i = x; i <= n; i += x) {
            rotate(i, d == 1 ? k : m - k);
        }

        remove();
    }
    cout << calc();

	return 0;
}
