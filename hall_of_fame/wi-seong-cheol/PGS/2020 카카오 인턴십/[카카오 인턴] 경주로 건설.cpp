//
//  [카카오 인턴] 경주로 건설.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

// 시간복잡도: O(n * m)
// 최악시간: 2,600
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/67259

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x7f7f7f7f;
int N;
int MAP[26][26][4];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Car {
    int X, Y, Cost, Dir;
};

bool OOB(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }

int bfs(vector<vector<int>>& board) {
    int min_cost = INF;
    queue<Car> Q;
    board[0][0] = 1;
    Q.push({0, 0, 0, 0});
    Q.push({0, 0, 0, 1});
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            fill(MAP[i][j], MAP[i][j] + 4, INF);
    
    MAP[0][0][0] = 0;
    MAP[0][0][1] = 0;
    
    while(!Q.empty()) {
        Car cur = Q.front(); Q.pop();

        if(cur.X == N - 1 && cur.Y == N - 1) {
            min_cost = min(min_cost, cur.Cost);
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            
            int ncost = cur.Cost;
            if(dir == cur.Dir) ncost += 100;
            else ncost += 600;
            
            if(MAP[nx][ny][dir] >= ncost) {
                Q.push({nx, ny, ncost, dir});
                MAP[nx][ny][dir] = ncost;
            }
        }
    }
    
    return min_cost;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    
    answer = bfs(board);
    
    return answer;
}
