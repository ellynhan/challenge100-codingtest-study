//
//  멀리 뛰기.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(n)
// 최악시간: 2,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const ll MOD = 1234567;
int cache[2001];

ll solve(int k) {
    if(k <= 1) return 1;
    int &ret = cache[k];
    if(ret != -1) return ret;
    ret = 0;

    ret += (solve(k - 2) + solve(k - 1)) % MOD;

    return ret;
}

ll solution(int n) {
    memset(cache, -1, sizeof(cache));
    ll answer = solve(n);

    return answer;
}
