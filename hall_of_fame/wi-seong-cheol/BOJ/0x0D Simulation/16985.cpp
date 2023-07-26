//
//  16985.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(2^10 * n * m)
// 최악시간: 15,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16985

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>

using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7;
int ans = INF;
// 0: 0도, 1: 90도, 2: 180도, 3: 270도
int board[4][5][5][5];
int maze[5][5][5];
int dx[6] = {1, 0, 0, 0, 0, -1};
int dy[6] = {0, 1, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 1, -1, 0};

bool OOB(int x, int y, int z) { return x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5; }

int solve() {
    
    int dist[5][5][5] = {0,};
    if(maze[0][0][0] == 0 || maze[4][4][4] == 0) return INF;
    
    queue<tuple<int, int, int>> Q;
    Q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){
            int x, y, z;
            tie(x, y, z) = cur;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(OOB(nx, ny, nz)) continue;
            if(maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
            if(nx == 4 && ny == 4 && nz == 4)
                return dist[x][y][z];
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 보드 입력 및 모든 층의 보드 회전
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];
        
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][4-k][j];
        
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][4-k][j];
        
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][4-k][j];
    }
    
    int order[5] = {0, 1, 2, 3, 4}; // 판을 쌓는 순서
    
    // 각 층의 방향을 모두 탐색
    do {
        for(int tmp = 0; tmp < 1024; tmp++){
            int brute = tmp;
            for(int i = 0; i < 5; i++){
                int dir = brute % 4;
                brute /= 4;
                for(int j = 0; j < 5; j++)
                    for(int k = 0; k < 5; k++)
                        maze[i][j][k] = board[dir][order[i]][j][k];
            }
            ans = min(ans, solve());
        }
    } while(next_permutation(order,order + 5));
    
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
