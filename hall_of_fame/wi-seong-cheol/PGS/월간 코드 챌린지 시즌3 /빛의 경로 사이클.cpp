//
//  빛의 경로 사이클.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/86052

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool vis[4][501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int nxtDir(char ch, int dir) {
    if(ch == 'S') return dir;
    if(ch == 'L') return (dir + 3) % 4;
    return (dir + 5) % 4;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int n = int(grid.size());
    int m = int(grid[0].size());

    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[dir][i][j]) continue;
                vis[dir][i][j] = true;
                int dist = 1;
                int curDir = dir;
                int x = i;
                int y = j;
                while(true) {
                    curDir = nxtDir(grid[x][y], curDir);
                    int nx = x + dx[curDir];
                    int ny = y + dy[curDir];
                    nx = (nx + n) % n;
                    ny = (ny + m) % m;
                    if(vis[curDir][nx][ny]) break;
                    dist++;
                    vis[curDir][nx][ny] = true;
                    x = nx;
                    y = ny;
                }
                answer.push_back(dist);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
