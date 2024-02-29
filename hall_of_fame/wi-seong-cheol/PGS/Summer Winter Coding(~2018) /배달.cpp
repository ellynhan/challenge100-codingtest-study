//
//  배달.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;
int dist[51][51];

void floyd(int N) {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    memset(dist, INF, sizeof(dist));
    for(int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    for(auto r: road) {
        dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
        dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2]);
    }
    floyd(N);

    for(int i = 1; i <= N; i++)
        if(dist[1][i] <= K) answer++;

    return answer;
}
