//
//  숫자 블록.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 25,000,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12923#

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1);

    for(ll i = 0; i < end - begin + 1; i++) {
        ll val;
        if(begin + i == 1) val = 0;
        else {
            vector<ll> num;
            for(ll x = 2; pow(x, 2) <= begin + i; x++) {
                if(x > 10000000) break;
                if((begin + i) % x == 0) {
                    num.push_back(x);
                    if((begin + i) / x <= 10000000) {
                        num.push_back((begin + i) / x);
                        break;
                    }
                }
            }
            if(num.empty()) val = 1;
            else {
                sort(num.begin(), num.end());
                val = num.back();
            }
        }

        answer[i] = val;
    }

    return answer;
}
