//
//  19236.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/24.
//

/*
 [Input]
 16 7 1 4 4 3 12 8
 14 7 7 6 3 4 10 2
 5 2 15 2 8 3 6 4
 11 8 2 4 13 5 9 4
 [Output]
 43
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 16
// 난이도: Gold 2
// Timer: 2h
// Url: https://www.acmicpc.net/problem/19236

#include <iostream>
#include <vector>

using namespace std;
#define X first
#define Y second
struct Fish {
    int dir, x, y, isDead;
};
int ans;
int val, dir;
tuple<int, int, int> shark;
vector<vector<int>> board(5);
vector<Fish> fish(17);
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

// 물고기 이동
void moveFish(vector<vector<int>>& board,
              vector<Fish>& fish,
              int sharkRow, int sharkCol) {
    for(int i = 1; i <= 16; i++) {
        if(fish[i].isDead == 1) continue;
        
        // 이동할 칸의 행열 값 구하여 이동 가능 여부 체크
        int nx = fish[i].x + dx[fish[i].dir];
        int ny = fish[i].y + dy[fish[i].dir];
        // cf) 물고기가 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.
        // cf) 각 물고기는 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다.
        while(OOB(nx, ny) || (nx == sharkRow && ny == sharkCol)) {
            fish[i].dir = (fish[i].dir + 1) % 8;
            nx = fish[i].x + dx[fish[i].dir];
            ny = fish[i].y + dy[fish[i].dir];
        }
        
        // cf) 물고기가 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸이다.
        if(board[nx][ny] == -1) { // 빈 칸일 경우
            board[nx][ny] = i;
            board[fish[i].x][fish[i].y] = -1;
            
            fish[i].x = nx;
            fish[i].y = ny;
        } else { // 다른 물고기가 있는 칸일 경우
            int exchangeFish = board[nx][ny];
            board[nx][ny] = i;
            board[fish[i].x][fish[i].y] = exchangeFish;
            
            fish[exchangeFish].x = fish[i].x;
            fish[exchangeFish].y = fish[i].y;
            fish[i].x = nx;
            fish[i].y = ny;
        }
    }
}

// 상어 이동
void solve(int val, int x, int y,
           vector<vector<int>> board,
           vector<Fish> fish) {
    vector<vector<int>> tempBoard(5);
    vector<Fish> tempFish(17);
    for(int i = 0; i < 4; i++) {
        tempBoard[i].resize(5);
        for(int j = 0; j < 4; j++) {
            tempBoard[i][j] = board[i][j];
        }
    }
    for(int i = 1; i <= 16; i++)
        tempFish[i] = fish[i];
    
    // 상어가 물고기를 먹음
    int targetFish = tempBoard[x][y];
    int sharkDir = tempFish[targetFish].dir;
    tempFish[targetFish].isDead = 1;
    tempBoard[x][y] = -1;
    val += targetFish;
    
    // 합이 최댓값일 경우 갱신
    if(val > ans)
        ans = val;
    
    // 물고기 이동
    moveFish(tempBoard, tempFish, x, y);
    
    for(int i = 1; i <= 3; i++) {
        int nx = x + dx[sharkDir] * i;
        int ny = y + dy[sharkDir] * i;
        if(OOB(nx, ny)) break;
        if(tempBoard[nx][ny] == -1) continue;
        solve(val, nx, ny, tempBoard, tempFish);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 4; i++) {
        board[i].resize(5);
        for(int j = 0; j < 4; j++) {
            cin >> val >> dir;
            board[i][j] = val;
            fish[val] = {dir - 1, i, j, 0};
        }
    }
    solve(0, 0, 0, board, fish);
    cout << ans;
    
    return 0;
}
