//
//  정수삼각형.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/11.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Level 3
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int d[501][501];

int solution(vector<vector<int>> triangle) {
    int h = triangle.size();
    
    d[1][1] = triangle[0][0];
    for(int i = 2; i <= h; i++) {
        for(int j = 1; j <= i; j++) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i - 1][j - 1];
        }
    }
    
    return *max_element(d[h], d[h] + h + 1);
}
