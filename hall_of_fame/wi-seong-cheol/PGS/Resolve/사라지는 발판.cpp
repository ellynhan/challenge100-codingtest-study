//
//  사라지는 발판.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 25
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92345

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
bool vis[5][5];
vector<vector<int>> board;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int solve(int curx, int cury, int nxtx, int nxty) {
    if(vis[curx][cury]) return 0;
    int ret = 0;

    for(int dir = 0; dir < 4; dir++) {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] == 0) continue;
        if(vis[nx][ny]) continue;
        vis[curx][cury] = true;
        int val = solve(nxtx, nxty, nx, ny) + 1;
        vis[curx][cury] = false;

        if(ret % 2 == 0 && val % 2 == 1)
            ret = val;
        else if(ret % 2 == 0 && val % 2 == 0)
            ret = max(ret, val);
        else if(ret % 2 == 1 && val % 2 == 1)
            ret = min(ret, val);
    }

    return ret;
}

int solution(vector<vector<int>> _board, vector<int> aloc, vector<int> bloc) {
    board = _board;
    n = int(board.size());
    m = int(board[0].size());
    int answer = solve(aloc[0], aloc[1], bloc[0], bloc[1]);
    return answer;
}
