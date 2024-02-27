//
//  방의 개수.cpp
//  main
//
//  Created by wi_seong on 2/19/24.
//

// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Level 5
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49190

#include <string>
#include <vector>
#include <map>

using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    int answer = 0;
    int n = int(arrows.size());
    map<pair<int, int>, bool> vis;
    map<pair<pair<int, int>, pair<int, int>>, bool> edgeVis;
    int x = 0;
    int y = 0;

    vis[{x, y}] = true;

    for(int i = 0; i < n; i++) {
        int dir = arrows[i];
        for(int j = 0; j < 2; j++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(vis[{nx, ny}] && !edgeVis[{{x, y}, {nx, ny}}]) {
                edgeVis[{{x, y}, {nx, ny}}] = true;
                edgeVis[{{nx, ny}, {x, y}}] = true;
                answer++;
                x = nx;
                y = ny;
                continue;
            }
            vis[{nx, ny}] = true;
            edgeVis[{{x, y}, {nx, ny}}] = true;
            edgeVis[{{nx, ny}, {x, y}}] = true;
            x = nx;
            y = ny;
        }
    }

    return answer;
}
