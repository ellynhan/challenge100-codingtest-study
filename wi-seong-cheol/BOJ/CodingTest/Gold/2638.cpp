//
//  2638.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 8 9
 0 0 0 0 0 0 0 0 0
 0 0 0 1 1 0 0 0 0
 0 0 0 1 1 0 1 1 0
 0 0 1 1 1 1 1 1 0
 0 0 1 1 1 1 1 0 0
 0 0 1 1 0 1 1 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 [Output]
 4
 */
// 시간복잡도: O(n * m * n)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2638

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, m;
int ans;                    // 모든 얼음이 녹는데 걸린 시간
int count_ice;              // 얼음의 총 갯수
int meltCount[101][101];    // 얼음이 닿은 면의 갯수
bool vis[101][101];
int board[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

// 맨 가장자리를 순회하면서 안쪽의 board를 녹여줌
void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 1) {
                meltCount[nx][ny]++;
            } else {
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}

void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
            meltCount[i][j] = 0;
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            count_ice += board[i][j];
        }
    
    // 얼음이 모두 녹을 때 까지 반복
    while(count_ice) {
        init();
        ans++;
        // 가장자리 순회
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    if(!board[i][j] && !vis[i][j])
                        bfs(i, j);
        // 바깥면에 두 면 이상 닿았으면 ice를 녹임
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(meltCount[i][j] >= 2) {
                    board[i][j] = 0;
                    count_ice--;
                }
    }
    cout << ans;
    
    return 0;
}
