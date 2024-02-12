//
//  억억단을 외우자.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,250,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/138475

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> factors;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void fillFactor(int n) {
    factors.resize(n + 1);
    for(int i = 1; i <= n; i++) factors[i] = {i, 0};

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i * j > n) break;
            factors[i * j].second++;
        }
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    fillFactor(e);

    sort(factors.begin(), factors.end(), cmp);

    for(int st: starts) {
        for(int i = 0; i <= e; i++) {
            if(factors[i].first >= st) {
                answer.push_back(factors[i].first);
                break;
            }
        }
    }

    return answer;
}
