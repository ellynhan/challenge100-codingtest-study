//
//  금과 은 운반하기.cpp
//  main
//
//  Created by wi_seong on 2/6/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 900,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/86053

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;
pair<int, int> goal;

bool isPossible(const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t, ll k) {
    ll total = 0;
    ll countGold = 0;
    ll countSilver = 0;

    for(int i = 0; i < n; i++) {
        ll cnt = k / (2 * ll(t[i]));
        if(k % (2 * ll(t[i])) >= t[i]) cnt++;

        ll tmp = min(cnt * ll(w[i]), ll(g[i] + s[i]));

        total += tmp;
        countGold += min(tmp, ll(g[i]));
        countSilver += min(tmp, ll(s[i]));
    }

    return countGold >= goal.first && countSilver >= goal.second && total >= ll(goal.first + goal.second);
}

ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    n = int(t.size());
    goal = {a, b};
    ll answer = 0;
    ll st = 0;
    ll en = 1e14 * 4 + 1;

    while(st <= en) {
        ll mid = (st + en + 1) / 2;

        if(isPossible(g, s, w, t, mid)) {
            en = mid - 1;
            answer = mid;
        } else {
            st = mid + 1;
        }
    }

    return answer;
}
