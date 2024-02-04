//
//  징검다리.cpp
//  main
//
//  Created by wi_seong on 2/2/24.
//

// 시간복잡도: O(nlgon)
// 최악시간: 450,000
// 난이도: Level 4
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43236

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int st = 1;
    int en = distance;

    while(st <= en) {
        int mid = (st + en) / 2;
        int cnt = 0;
        int prev = 0;

        for(int i = 0; i < int(rocks.size()); i++) {
            if(rocks[i] - prev < mid)
                cnt++;
            else
                prev = rocks[i];
        }

        if(cnt <= n) {
            st = mid + 1;
            answer = max(answer, mid);
        } else {
            en = mid - 1;
        }
    }

    return answer;
}
