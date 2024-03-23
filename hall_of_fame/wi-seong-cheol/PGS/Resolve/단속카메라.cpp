//
//  단속카메라.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 240,000
// 난이도: Level 3
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int pos = -INF;

    for(auto route: routes) {
        if(pos < route[0]) {
            answer++;
            pos = route[1];
        }
    }

    return answer;
}
