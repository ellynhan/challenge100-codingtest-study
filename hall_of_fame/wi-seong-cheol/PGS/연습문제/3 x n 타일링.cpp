//
//  3 x n 타일링.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n)
// 최악시간: 5,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12902

#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll cache[5001];

ll solve(int k) {
    if(k <= 1) return 1;
    ll &ret = cache[k];
    if(ret != -1) return ret;
    ret = 0;

    if(k % 2 == 0) {
        ret += (solve(k - 2) * 3) % MOD;
        if(k >= 4) ret += (solve(k - 3) * 2) % MOD;
    } else {
        ret += solve(k - 1) % MOD;
        ret += solve(k - 2) % MOD;
    }

    return ret % MOD;
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    int answer = solve(n);

    return answer;
}
