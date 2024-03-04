//
//  땅따먹기.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,600,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12913

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = int(land.size());

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            int mx = 0;
            for(int k = 0; k < 4; k++) {
                if(j == k) continue;
                mx = max(mx, land[i - 1][k]);
            }
            land[i][j] += mx;
        }
    }
    answer = *max_element(land[n - 1].begin(), land[n - 1].end());

    return answer;
}
