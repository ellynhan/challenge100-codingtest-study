//
//  시소 짝궁.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/152996#

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll solution(vector<int> weights) {
    ll answer = 0;
    int n = int(weights.size());
    vector<ll> cnt(1001, 0);

    for(int i = 0; i < n; i++)
        cnt[weights[i]]++;

    for(int i = 0; i < n; i++) {
        if(weights[i] % 2 == 0) {
            ll base  = (weights[i] / 2) * 3;
            if(base <= 1000)    answer += cnt[base];
        }
        if(weights[i] % 3 == 0) {
            ll base  = (weights[i] / 3) * 4;
            if(base <= 1000)    answer += cnt[base];
        }
        ll base  = weights[i] * 2;
        if(base <= 1000)    answer += cnt[base];
    }

    for(ll element: cnt) {
        if(element >= 2) {
            answer += (ll)(element * (element - 1)) / 2;
        }
    }

    return answer;
}
