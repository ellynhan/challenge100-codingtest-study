//
//  정수 삼각형.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Level 3
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int d[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = int(triangle.size());

    d[1][1] = triangle[0][0];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + triangle[i - 1][j - 1];
        }
    }

    answer = *max_element(d[n], d[n] + n + 1);

    return answer;
}
