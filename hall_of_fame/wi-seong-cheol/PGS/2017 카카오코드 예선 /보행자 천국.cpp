//
//  보행자 천국.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Level 3
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1832

#include <vector>
#include <iostream>

using namespace std;
const int MOD = 20170805;
const int MXN = 501;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    long long d[2][501][501] = { 0 };

    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1) break;
        d[0][i][0] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1) break;
        d[1][0][i] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(city_map[i][j] == 1) continue;
            // 윗쪽
            if(city_map[i - 1][j] == 0) {
                d[0][i][j] += (d[0][i - 1][j] + d[1][i - 1][j]) % MOD;
            } else if(city_map[i - 1][j] == 2) {
                d[0][i][j] += d[0][i - 1][j];
            }
            // 왼쪽
            if(city_map[i][j - 1] == 0) {
                d[1][i][j] += (d[0][i][j - 1] + d[1][i][j - 1]) % MOD;
            } else if(city_map[i][j - 1] == 2) {
                d[1][i][j] += d[1][i][j - 1];
            }
        }
    }
    answer = (d[0][m - 1][n - 1] + d[1][m - 1][n - 1]) % MOD;

    return answer;
}
