//
//  카드 짝 맞추기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(2 ^ (n * m))
// 최악시간: 65,536
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/72415

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define pii pair<int, int>
#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

int dist(vector<vector<int>>& board, pii src, pii dst) {
    int d[4][4];
    for(int i = 0; i < 4; i++)
        fill(d[i], d[i] + 4, -1);
    d[src.X][src.Y] = 0;
    queue<pii> Q;
    Q.push(src);
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int en = 0; // dir 방향으로 진행할 때 카드 혹은 마지막 까지의 거리
            while(true){
                int nx = cur.X + dx[dir] * en;
                int ny = cur.Y + dy[dir] * en;
                if(OOB(nx + dx[dir], ny + dy[dir]) || (en != 0 && board[nx][ny] != 0)) break;
                en++;
            }
            for(int z : {1, en}){
                int nx = cur.X + dx[dir] * z;
                int ny = cur.Y + dy[dir] * z;
                if(OOB(nx,ny)) continue;
                if(d[nx][ny] == -1) {
                    d[nx][ny] = d[cur.X][cur.Y] + 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return d[dst.X][dst.Y];
}


int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x7f7f7f7f;
    vector<int> p;
    vector<pii> occur[7];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(board[i][j] != 0)
                occur[board[i][j]].push_back({i, j});
    
    for(int i = 1; i <= 6; i++)
        if(!occur[i].empty()) p.push_back(i);
    int n = p.size();
    
    do {
        vector<vector<int>> myboard = board;
        int d[6][2];
        d[0][0] = dist(myboard, {r, c}, occur[p[0]][0]) + dist(myboard, occur[p[0]][0], occur[p[0]][1]);
        d[0][1] = dist(myboard, {r, c}, occur[p[0]][1]) + dist(myboard, occur[p[0]][1], occur[p[0]][0]);
        myboard[occur[p[0]][0].X][occur[p[0]][0].Y] = 0;
        myboard[occur[p[0]][1].X][occur[p[0]][1].Y] = 0;
        for(int i = 1; i < n; i++){
            d[i][0] = min(d[i-1][0] + dist(myboard, occur[p[i-1]][1], occur[p[i]][0]), d[i-1][1] + dist(myboard, occur[p[i-1]][0], occur[p[i]][0])) + dist(myboard, occur[p[i]][0], occur[p[i]][1]);
            d[i][1] = min(d[i-1][0] + dist(myboard, occur[p[i-1]][1], occur[p[i]][1]), d[i-1][1] + dist(myboard, occur[p[i-1]][0], occur[p[i]][1])) + dist(myboard, occur[p[i]][1], occur[p[i]][0]);
            myboard[occur[p[i]][0].X][occur[p[i]][0].Y] = 0;
            myboard[occur[p[i]][1].X][occur[p[i]][1].Y] = 0;
        }
        answer = min({answer, d[n-1][0], d[n-1][1]});
    } while(next_permutation(p.begin(), p.end()));
    
    return answer + 2 * n;
}
