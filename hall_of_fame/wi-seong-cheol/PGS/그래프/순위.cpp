//
//  순위.cpp
//  main
//
//  Created by wi_seong on 1/31/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49191

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int d[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(auto result: results) {
        int u = result[0];
        int v = result[1];
        d[u][v] = 1;
        d[v][u] = -1;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(d[i][j] != 0) continue;
                if(d[i][k] == 1 && d[k][j] == 1) {
                    d[i][j] = 1;
                } else if(d[i][k] == -1 && d[k][j] == -1) {
                    d[i][j] = -1;
                }
            }

    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            cnt += d[i][j] == 0 ? 1 : 0;
        }
        answer += cnt == 1 ? 1 : 0;
    }

    return answer;
}
