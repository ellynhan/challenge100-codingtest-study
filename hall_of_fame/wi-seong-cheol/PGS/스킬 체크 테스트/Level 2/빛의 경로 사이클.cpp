//
//  빛의 경로 사이클.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/86052

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<string> board;
bool vis[501][501][4];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int changeDir(char ch, int dir) {
    if(ch == 'L') {
        if(dir == 0) return 3;
        if(dir == 1) return 2;
        if(dir == 2) return 0;
        if(dir == 3) return 1;
    }

    if(dir == 0) return 2;
    if(dir == 1) return 3;
    if(dir == 2) return 1;
    if(dir == 3) return 0;
}

int dfs(int x, int y, int dir, int cnt) {
    if(vis[x][y][dir] == true) return cnt;
    vis[x][y][dir] = true;

    int nx = x;
    int ny = y;
    int nd = dir;

    if(board[x][y] != 'S') nd = changeDir(board[x][y], dir);
    nx = x + dx[nd];
    ny = y + dy[nd];
    if(nx < 0) nx = n - 1;
    if(ny < 0) ny = m - 1;
    if(nx == n) nx = 0;
    if(ny == m) ny = 0;

    return dfs(nx, ny, nd, cnt + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    n = grid.size();
    m = grid[0].size();
    board = grid;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int dir = 0; dir < 4; dir++) {
                int result = dfs(i, j, dir, 0);
                if(result != 0) answer.push_back(result);
            }
    sort(answer.begin(), answer.end());

    return answer;
}
