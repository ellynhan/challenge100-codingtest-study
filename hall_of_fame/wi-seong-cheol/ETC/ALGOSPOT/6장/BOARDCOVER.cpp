//
//  BOARDCOVER.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 3
 3 7
 #.....#
 #.....#
 ##...##
 3 7
 #.....#
 #.....#
 ##..###
 8 10
 ##########
 #........#
 #........#
 #........#
 #........#
 #........#
 #........#
 ##########
 [Output]
 0
 2
 1514
 */
// 시간복잡도: O(4 ^ (3 / n))
// 최악시간: 4,294,967,296
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <vector>

using namespace std;
int t, n, m;
int cnt;
vector<vector<int>> board;
const int coverType[4][3][2] {
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

void init() {
    for(int i = 0; i < n; i++)
        board[i].clear();
    board.clear();
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

bool set(vector<vector<int>>& board, int x, int y, int type, int delta) {
    bool ret = true;
    for(int i = 0; i < 3; i++) {
        const int nx = x + coverType[type][i][0];
        const int ny = y + coverType[type][i][1];
        if(OOB(nx, ny)) ret = false;
        else if((board[nx][ny] += delta) > 1) ret = false;
    }
    return ret;
}

int solve(vector<vector<int>>& board) {
    int x = -1;
    int y = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        if(x != -1) break;
    }

    if(x == -1) return 1;
    int ret = 0;

    for(int type = 0; type < 4; type++) {
        if(set(board, x, y, type, 1))
            ret += solve(board);
        set(board, x, y, type, -1);
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        cnt = 0;
        cin >> n >> m;
        board.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch; cin >> ch;
                if(ch == '#') board[i].push_back(1);
                else board[i].push_back(0);
            }
        }
        cout << solve(board) << '\n';
    }

	return 0;
}
