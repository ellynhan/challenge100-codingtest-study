//
//  재밌는 레이싱 경기장 설계하기.cpp
//  main
//
//  Created by wi_seong on 2/20/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 1,200,000
// 난이도: Level 5
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/214292#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> heights) {
    int n = int(heights.size());
    sort(heights.begin(), heights.end());
    vector<int> minusV;

    if(n % 2 == 1) {
        for(int i = 0; i < n / 2; i++) {
            minusV.push_back(heights[i + (n / 2)] - heights[i]);
        }
        minusV.push_back(heights[n - 1] - heights[n / 2]);
        sort(minusV.begin(), minusV.end());
        return minusV[1];
    } else {
        for(int i = 0; i < n / 2; i++) {
            minusV.push_back(heights[i + (n / 2)] - heights[i]);
        }
        sort(minusV.begin(), minusV.end());
        return minusV[0];
    }

    return 0;
}
