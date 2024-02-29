//
//  연속 부분 수열 합의 개수.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131701

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int n = int(elements.size());
    vector<int> psum;
    psum.resize(n * 2 + 1);
    psum[0] = 0;
    psum[1] = elements[0];

    for(int i = 1; i < n; i++) {
        psum[i + 1] = psum[i] + elements[i];
    }
    for(int i = 0; i < n; i++) {
        psum[n + i + 1] = psum[n + i] + elements[i];
    }

    unordered_set<int> s;
    for(int i = 1; i <= n; i++) {
        for(int len = 1; len <= n; len++) {
            s.insert(psum[i + len - 1] - psum[i - 1]);
        }
    }
    answer = int(s.size());

    return answer;
}
