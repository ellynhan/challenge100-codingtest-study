//
//  인사고과.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/152995#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a.front() == b.front()) return a.back() < b.back();
    return a.front() > b.front();
}

int solution(vector<vector<int>> scores) {
    int answer = 1;

    vector<int> wanho = scores.front();
    int wanhoSum = wanho.front() + wanho.back();

    sort(scores.begin(), scores.end(), cmp);

    int MAX_VALUE = -1;
    for(auto& score: scores) {
        if(MAX_VALUE < score.back()) MAX_VALUE = score.back();
        else if(MAX_VALUE > score.back()) {
            if(wanho.front() == score.front() && wanho.back() == score.back()) return -1;
            continue;
        }
        if(score.front() + score.back() > wanhoSum) answer++;
    }

    return answer;
}
