//
//  17780.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 4 4
 0 0 2 0
 0 0 1 0
 0 0 1 2
 0 2 0 0
 2 1 1
 3 2 3
 2 2 1
 4 1 2
 [Output]
 -1
 */
// 시간복잡도: O(n^2 * k)
// 최악시간: 1,440,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17780

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, k;
int board[13][13];
vector<vector<vector<pair<int, int>>>> chess;
pair<int, int> pos[11];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool play() {
    bool isEnd = false;
    
    for(int i = 0; i < k; i++) {
        int x = pos[i].X;
        int y = pos[i].Y;

        if(chess[x][y][0].X != i) continue;
        
        int d = chess[x][y][0].Y;
        int nx = x + dx[d];
        int ny = y + dy[d];
        // 파란색 or 범위 밖
        if(OOB(nx, ny) || board[nx][ny] == 2) {
            d = d % 2 ? d - 1 : d + 1;
            nx = x + dx[d];
            ny = y + dy[d];
            chess[x][y][0].Y = d;
            if(OOB(nx, ny) || board[nx][ny] == 2) continue;
            if(board[nx][ny] == 1) {
                for(int i = int(chess[x][y].size() - 1); i >= 0; i--) {
                    chess[nx][ny].push_back(chess[x][y][i]);
                    pos[chess[x][y][i].X] = {nx, ny};
                }
            } else {
                for(auto element: chess[x][y]) {
                    chess[nx][ny].push_back(element);
                    pos[element.X] = {nx, ny};
                }
            }
            chess[x][y].clear();
            if(chess[nx][ny].size() >= 4) {
                isEnd = true;
                break;
            }
        } else { // 흰색 or 빨간색
            if(board[nx][ny] == 1) {
                for(int i = int(chess[x][y].size() - 1); i >= 0; i--) {
                    chess[nx][ny].push_back(chess[x][y][i]);
                    pos[chess[x][y][i].X] = {nx, ny};
                }
            } else {
                for(auto element: chess[x][y]) {
                    chess[nx][ny].push_back(element);
                    pos[element.X] = {nx, ny};
                }
            }
            chess[x][y].clear();
            if(chess[nx][ny].size() >= 4) {
                isEnd = true;
                break;
            }
        }
    }

    return isEnd;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    chess.resize(n, vector<vector<pair<int, int>>>(n));
    for(int i = 0; i < n; i++)
        chess[i].resize(n, vector<pair<int, int>>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    for(int i = 0; i < k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        chess[x - 1][y - 1].push_back({i, --d});
        if(chess[x - 1][y - 1].size() == 4) {
            cout << -1;
            return 0;
        }
        pos[i] = {x - 1, y - 1};
    }
    
    for(int turn = 1; turn < 1001; turn++) {
        if(play()) {
            cout << turn;
            return 0;
        }
    }
    cout << -1;

	return 0;
}
/*
 6 10
 1 0 2 0 1 1
 1 2 0 1 1 0
 2 1 0 1 1 0
 1 0 1 1 0 2
 2 0 1 2 0 1
 0 2 1 0 2 1

 0 1 0 0 0 0
 2 0 0 9 0 7
 0 0 0 0 0 0
 0 0 3& 0 45 0
 0 0 0 0 0 0
 8 0 0 0 0 6

 1: 1 1 1
 2: 2 2 2
 3: 3 3 4
 4: 4 4 1
 5: 5 5 3
 6: 6 6 1
 7: 1 6 4
 8: 6 1 2
 9: 2 4 3
 &: 4 2 1
 */
