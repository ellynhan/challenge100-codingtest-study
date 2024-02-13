//
//  기지국 설치.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12979

#include <iostream>
#include <vector>

using namespace std;

int solution(int cnt, vector<int> stations, int w) {
    int answer = 0;
    stations.push_back(cnt + w + 1);
    int n = int(stations.size());

    int prev = 0;
    int range = 1 + (w * 2);
    for(int i = 0; i < n; i++) {
        int interval = stations[i] - w - prev - 1;
        int val = interval < 1 ? 0 : interval;
        prev = stations[i] + w;
        answer += val / range + (val % range != 0);
    }

    return answer;
}
