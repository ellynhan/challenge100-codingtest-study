//
//  10709.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 6 8
 .c......
 ........
 .ccc..c.
 ....c...
 ..c.cc..
 ....c...
 [Output]
 -1 0 1 2 3 4 5 6
 -1 -1 -1 -1 -1 -1 -1 -1
 -1 0 0 0 1 2 0 1
 -1 -1 -1 -1 0 1 2 3
 -1 -1 0 1 0 0 1 2
 -1 -1 -1 -1 0 1 2 3 
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/10709

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define X first
#define Y second
int n, m;
int board[101][101];
vector<pair<int, int>> C;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(board, -1, sizeof(board));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch; cin >> ch;
            if(ch == 'c') {
                board[i][j] = 0;
                C.push_back({i, j});
            }
        }
    }
    while(!C.empty()) {
        for(int i = 0; i < C.size(); i++) {
            int nx = C[i].X;
            int ny = C[i].Y + 1;
            if(ny >= m) {
                C.erase(C.begin() + i--);
                continue;
            }
            if(board[nx][ny] == -1)
                board[nx][ny] = board[C[i].X][C[i].Y] + 1;
            C[i].Y++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
