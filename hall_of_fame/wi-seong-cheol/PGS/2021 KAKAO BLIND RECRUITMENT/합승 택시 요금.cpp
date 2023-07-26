//
//  합승 택시 요금.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000,000
// 난이도: Level 3
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
int N;
int d[201][201];

void floyd() {
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    N = n;
    for(int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        d[i][i] = 0;
    }
    for(auto fare: fares) {
        d[fare[0]][fare[1]] = fare[2];
        d[fare[1]][fare[0]] = fare[2];
    }
    floyd();
    for(int i = 1; i <= n; i++) {
        if(d[s][i] == INF || d[i][a] == INF || d[i][b] == INF) continue;
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    
    return answer;
}
