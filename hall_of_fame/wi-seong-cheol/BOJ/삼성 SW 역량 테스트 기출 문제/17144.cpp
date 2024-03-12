//
//  17144.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 7 8 5
 0 0 0 0 0 0 0 9
 0 0 0 0 3 0 0 8
 -1 0 5 0 0 0 22 0
 -1 8 0 0 0 0 0 0
 0 0 0 0 0 10 43 0
 0 0 5 0 15 0 0 0
 0 0 40 0 0 0 20 0
 [Output]
 172
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Gold 4
// Timer: 22m
// Url: https://www.acmicpc.net/problem/17144

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct Point {
    int x, y;
};
int r, c, t;
int board[51][51];
int tmp[51][51];
vector<Point> robot;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

void spread(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(OOB(nx, ny) || board[nx][ny] == -1) continue;
        tmp[nx][ny] += board[x][y] / 5;
        cnt++;
    }
    tmp[x][y] += board[x][y] - (board[x][y] / 5) * cnt;
}

void move() {
    for(int i = robot[0].x - 1; i > 0; i--) {
        board[i][0] = board[i - 1][0];
    }
    for(int i = 0; i < c - 1; i++) {
        board[0][i] = board[0][i + 1];
    }
    for(int i = 0; i < robot[0].x; i++) {
        board[i][c - 1] = board[i + 1][c - 1];
    }
    for(int i = c - 1; i > 1; i--) {
        board[robot[0].x][i] = board[robot[0].x][i - 1];
    }
    board[robot[0].x][1] = 0;
    for(int i = robot[1].x + 1; i < r - 1; i++) {
        board[i][0] = board[i + 1][0];
    }
    for(int i = 0; i < c - 1; i++) {
        board[r - 1][i] = board[r - 1][i + 1];
    }
    for(int i = r - 1; i > robot[1].x; i--) {
        board[i][c - 1] = board[i - 1][c - 1];
    }
    for(int i = c - 1; i > 1; i--) {
        board[robot[1].x][i] = board[robot[1].x][i - 1];
    }
    board[robot[1].x][1] = 0;
}

int countDust() {
    int result = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] > 0) {
                result += board[i][j];
            }
        }
    }
    return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) {
                robot.push_back({i, j});
            }
        }
    }

    while(t--) {
        memset(tmp, 0, sizeof(tmp));
        tmp[robot[0].x][0] = -1;
        tmp[robot[1].x][0] = -1;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] > 0) {
                    spread(i, j);
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                board[i][j] = tmp[i][j];
            }
        }
        move();
    }
    int result = countDust();
    cout << result;

	return 0;
}
