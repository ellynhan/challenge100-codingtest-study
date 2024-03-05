//
//  14502.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 7 7
 2 0 0 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 0 1 0 0
 0 1 0 0 0 0 0
 0 0 0 0 0 1 1
 0 1 0 0 0 0 0
 0 1 0 0 0 0 0
 [Output]
 27
 */
// 시간복잡도: O(n * m * (2^n))
// 최악시간: 16,384
// 난이도: Gold 4
// Timer: 14m
// Url: https://www.acmicpc.net/problem/14502

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int answer;
int n, m;
int board[10][10];
bool vis[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            if(vis[nx][ny]) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

int countSafe() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && board[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> brute(n * m, 0);
    fill(brute.begin() + n * m - 3, brute.end(), 1);
    do {
        vector<pair<int, int>> p;
        bool flag = false;
        for(int i = 0; i < n * m; i++) {
            if(brute[i]) {
                if(board[i / m][i % m] != 0) {
                    flag = true;
                    break;
                }
                p.push_back({i / m, i % m});
            }
        }
        if(flag) continue;
        memset(vis, false, sizeof(vis));

        for(auto element: p)
            board[element.first][element.second] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != 2 || vis[i][j]) continue;
                bfs(i, j);
            }
        }

        answer = max(answer, countSafe());

        for(auto element: p)
            board[element.first][element.second] = 0;
    } while(next_permutation(brute.begin(), brute.end()));
    cout << answer;

	return 0;
}
