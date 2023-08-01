//
//  17822.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 6 3
 1 2 3 4 5 6
 2 3 4 5 6 7
 3 4 5 6 7 8
 4 5 6 7 8 9
 2 1 4
 3 0 1
 2 1 2
 [Output]
 26
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17822

#include <iostream>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, t;
int x, d, k;
deque<int> board[51];
bool vis[51][51];
bool isAdj;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void rotate() {
    for(int i = x - 1; i < n; i += x) {
        for(int j = 0; j < k; j++) {
            if(d == 0) {
                board[i].push_front(board[i].back());
                board[i].pop_back();
            } else {
                board[i].push_back(board[i].front());
                board[i].pop_front();
            }
        }
    }
}

void erase(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    bool isDelete = false;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(ny < 0) ny = m - 1;
            if(ny >= m) ny = 0;
            if(nx < 0 || nx >= n || vis[nx][ny]) continue;
            if(board[nx][ny] != board[x][y]) continue;
            isDelete = true;
            board[nx][ny] = 0;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    
    if(isDelete) {
        board[x][y] = 0;
        isAdj = true;
    }
}

void isNotAdj() {
    double sum = 0;
    double cnt = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] != 0) {
                cnt++;
                sum += (double)board[i][j];
            }
    
    double avg = sum / cnt;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) continue;
            if(avg > (double)board[i][j]) board[i][j]++;
            else if(avg < (double)board[i][j]) board[i][j]--;
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> x;
            board[i].push_back(x);
        }
    while(t--) {
        memset(vis, false, sizeof(vis));
        isAdj = false;
        cin >> x >> d >> k;
        rotate();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && board[i][j]) erase(i, j);
        if(!isAdj) isNotAdj();
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += board[i][j];
    cout << ans;
    
    return 0;
}
