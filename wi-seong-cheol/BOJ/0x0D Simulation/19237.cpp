//
//  19237.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/24.
//

/*
 [Input]
 5 4 4
 0 0 0 0 3
 0 2 0 0 0
 1 0 0 0 4
 0 0 0 0 0
 0 0 0 0 0
 4 4 3 1
 2 3 1 4
 4 1 2 3
 3 4 2 1
 4 3 1 2
 2 4 3 1
 2 1 3 4
 3 4 1 2
 4 1 2 3
 4 3 2 1
 1 4 3 2
 1 3 2 4
 3 2 1 4
 3 4 1 2
 3 2 4 1
 1 4 2 3
 1 4 2 3
 [Output]
 14
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000
// 난이도: Gold 2
// Timer: 1h 30m
// Url: https://www.acmicpc.net/problem/19237

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define X first
#define Y second
struct Shark {
    int dir, x, y;
    int pq[4][4];
    bool die;
};
int n, m, k, t;
vector<Shark> shark;
pair<int, int> board[21][21];
int dx[] = {-1, 1, 0, 0}; // 위, 아래, 왼쪽, 오른쪽
int dy[] = {0, 0, -1, 1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

// 상어 냄새 지우기
void removeSmell() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(board[i][j].X > 0)
                board[i][j].X--;
            if(board[i][j].X == 0)
                board[i][j] = {0, 0};
        }
}

// 상어 냄새 채우기
void makeSmell() {
    bool vis[n][n];
    memset(vis, false, sizeof(vis));
    
    for(int i = 0; i < shark.size(); i++) {
        if(shark[i].die) continue;
        int x = shark[i].x;
        int y = shark[i].y;
        if(vis[x][y]) {
            shark[i].die = true;
        } else {
            board[x][y] = {k, i + 1};
            vis[x][y] = true;
        }
    }
    
}

void moveShark() {
    for(int i = 0; i < shark.size(); i++) {
        if(shark[i].die) continue;
        bool isMove = false;
        for(int dir: shark[i].pq[shark[i].dir - 1]) {
            int nx = shark[i].x + dx[dir - 1];
            int ny = shark[i].y + dy[dir - 1];
            if(OOB(nx, ny) || board[nx][ny].X > 0) continue;
            shark[i].dir = dir;
            shark[i].x = nx;
            shark[i].y = ny;
            isMove = true;
            break;
        }
        if(!isMove) {
            for(int dir: shark[i].pq[shark[i].dir - 1]) {
                int nx = shark[i].x + dx[dir - 1];
                int ny = shark[i].y + dy[dir - 1];
                if(OOB(nx, ny) || board[nx][ny].Y != i + 1) continue;
                shark[i].dir = dir;
                shark[i].x = nx;
                shark[i].y = ny;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    shark.resize(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int number; cin >> number;
            if(number == 0) continue;
            shark[number - 1].x = i;
            shark[number - 1].y = j;
            board[i][j] = {k, number};
        }
    }
    for(int i = 0; i < m; i++)
        cin >> shark[i].dir;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                cin >> shark[i].pq[j][k];
    
    while(t <= 1000) {
        // 상어가 하나 남으면 종료
        int cnt = 0;
        for(int i = 0; i < shark.size(); i++)
            cnt += !shark[i].die;
        if(cnt == 1) {
            cout << t;
            return 0;
        }
        t++;
        
        // 상어 움직임
        moveShark();
        // 상어 냄새 -1
        removeSmell();
        // 냄새 채우기
        makeSmell();
    }
    cout << -1;
    
    return 0;
}
