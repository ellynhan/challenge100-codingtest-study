//
//  14503.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 11 10
 7 4 0
 1 1 1 1 1 1 1 1 1 1
 1 0 0 0 0 0 0 0 0 1
 1 0 0 0 1 1 1 1 0 1
 1 0 0 1 1 0 0 0 0 1
 1 0 1 1 0 0 0 0 0 1
 1 0 0 0 0 0 0 0 0 1
 1 0 0 0 0 0 0 1 0 1
 1 0 0 0 0 0 1 1 0 1
 1 0 0 0 0 0 1 1 0 1
 1 0 0 0 0 0 0 0 0 1
 1 1 1 1 1 1 1 1 1 1
 [Output]
 57
 */
// 시간복잡도: O(n * m)
// 최악시간: 250
// 난이도: Gold 5
// Timer: 28m
// Url: https://www.acmicpc.net/problem/14503

#include <iostream>
#include <queue>

using namespace std;
struct Robot {
    int x, y, dir;
};
int n, m;
int x, y, dir;
int board[51][51];
bool vis[51][51];
Robot r;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int backDir() {
    return (r.dir + 2) % 4;
}

int rotateDir() {
    return (r.dir + 3) % 4;
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs() {
    int cnt = 0;

    while(true) {
        bool flag = false;
        // 청소가 가능하면 카운트
        if(!vis[r.x][r.y]) cnt++;
        vis[r.x][r.y] = true;

        // 상하좌우 청소되지 않은 빈칸 확인
        for(int dir = 0; dir < 4; dir++) {
            int nx = r.x + dx[dir];
            int ny = r.y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            if(vis[nx][ny]) continue;
            flag = true;
            break;
        }

        if(!flag) { // 청소되지 않은 빈칸이 없을 때
            int nextDir = backDir();
            int nx = r.x + dx[nextDir];
            int ny = r.y + dy[nextDir];
            if(OOB(nx, ny) || board[nx][ny] == 1) { // 후진이 불가능하면
                break;
            } else {  // 후진이 가능하면
                r.x = nx;
                r.y = ny;
            }
        } else { // 청소되지 않은 빈칸이 있을 때
            r.dir = rotateDir();  // 회전
            int nx = r.x + dx[r.dir];
            int ny = r.y + dy[r.dir];
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            if(vis[nx][ny]) continue;
            r.x = nx;
            r.y = ny;
        }
    }

    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    cin >> x >> y >> dir;
    r = {x, y, dir};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs();

	return 0;
}
