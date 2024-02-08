//
//  입국심사.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43238#

#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;

bool solve(ll n, ll k, const vector<ll>& times) {
    ll ret = 0;

    for(ll time: times)
        ret += k / time;

    return ret >= n;
}

ll solution(int n, vector<int> times) {
    ll answer = 0;
    vector<ll> t;
    for(int time: times)
        t.push_back((ll)(time));

    ll st = 1;
    ll en = n * (*max_element(t.begin(), t.end()));

    while(st <= en) {
        ll mid = (st + en) / 2;

        if(solve(n, mid, t)) {
            en = mid - 1;
            answer = mid;
        } else {
            st = mid + 1;
        }
    }

    return answer;
}
