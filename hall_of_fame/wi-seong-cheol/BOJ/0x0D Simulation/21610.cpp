//
//  21610.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/30/23.
//

/*
 [Input]
 5 4
 0 0 1 0 2
 2 3 2 1 0
 4 3 2 9 0
 1 0 2 9 0
 8 8 2 1 0
 1 3
 3 4
 8 1
 4 8
 [Output]
 77
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21610

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define X first
#define Y second
int n, m, d, s;
int ans;
vector<pair<int, int>> clouds;   // 구름 좌표
bool eraseCloud[51][51];
int board[51][51];
int cdx[] = {0, -1, -1, -1, 0, 1, 1, 1};    // 구름 이동방향
int cdy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {-1, -1, 1, 1};  // 물 복사 대각선 방향
int dy[] = {-1, 1, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void changePoint(int& x, int& y) {
    if(x < 0) x += n;
    if(x >= n) x -= n;
    if(y < 0) y += n;
    if(y >= n) y -= n;
}

void moveCloud() {
    for(auto& cloud: clouds) {
        int nx = cloud.X + cdx[d] * (s % n);
        int ny = cloud.Y + cdy[d] * (s % n);
        changePoint(nx, ny);
        cloud = {nx, ny};
    }
}

void rain() {
    for(auto& cloud: clouds)
        board[cloud.X][cloud.Y]++;
}

void waterCopy() {
    for(auto& cloud: clouds) {
        int cnt = 0;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cloud.X + dx[dir];
            int ny = cloud.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 0) continue;
            cnt++;
        }
        eraseCloud[cloud.X][cloud.Y] = true;
        board[cloud.X][cloud.Y] += cnt;
    }

    clouds.clear();
}

void createCloud() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(eraseCloud[i][j] || board[i][j] <= 1) continue;
            board[i][j] -= 2;
            clouds.push_back({i, j});
        }
    }
}

void calculate() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans += board[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    // 초기 구름
    clouds.push_back({n - 2, 0});
    clouds.push_back({n - 2, 1});
    clouds.push_back({n - 1, 0});
    clouds.push_back({n - 1, 1});

    while(m--) {
        memset(eraseCloud, false, sizeof(eraseCloud));

        cin >> d >> s;
        d--;

        // 구름 이동
        moveCloud();
        // 비 내리기
        rain();
        //물 복사
        waterCopy();
        // 구름 생성
        createCloud();
    }
    calculate();
    cout << ans;

    return 0;
}
