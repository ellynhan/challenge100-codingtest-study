//
//  최적의 행렬 곱셈.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12942

#include <vector>
#include <climits>
#include <cstring>

using namespace std;

vector<vector<int>> matrix;
int cache[201][201];

int dp(int st, int en) {
    int &ret = cache[st][en];
    if(ret != -1) return ret;
    if(st == en) return 0;
    int minimum = INT_MAX;

    for(int i = st; i < en; ++i) {
        int cost = dp(st, i) + dp(i + 1, en) + matrix[st][0] * matrix[i + 1][0] * matrix[en][1];
        if (cost < minimum) {
            minimum = cost;
            ret = minimum;
        }
    }

    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    matrix = matrix_sizes;
    memset(cache, -1, sizeof(cache));
    int answer = dp(0, int(matrix.size()) - 1);
    return answer;
}
