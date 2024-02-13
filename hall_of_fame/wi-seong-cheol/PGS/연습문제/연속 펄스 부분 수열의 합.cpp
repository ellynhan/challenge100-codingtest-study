//
//  연속 펄스 부분 수열의 합.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/161988

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

ll solve(const vector<int>& sequence) {
    int n = int(sequence.size());
    ll asum[n];

    asum[0] = sequence[0];
    for(int i = 1; i < n; i++)
        asum[i] = max(ll(0), asum[i - 1]) + ll(sequence[i]);

    return *max_element(asum, asum + n);
}

ll solution(vector<int> sequence) {
    ll answer = 0;
    int n = int(sequence.size());
    vector<int> s1, s2;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            s1.push_back(sequence[i]);
            s2.push_back(-1 * sequence[i]);
        } else {
            s1.push_back(-1 * sequence[i]);
            s2.push_back(sequence[i]);
        }
    }
    answer = max(solve(s1), solve(s2));

    return answer;
}
