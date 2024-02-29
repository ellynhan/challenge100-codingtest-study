//
//  2 x n 타일링.cpp
//  main
//
//  Created by wi_seong on 2/12/24.
//

// 시간복잡도: O(n)
// 최악시간: 60,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12900

#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int MOD = 1e9 + 7;
int cache[60001];

int solve(int k) {
    if(k == 0) return 1;
    int &ret = cache[k];
    if(ret != -1) return ret;
    ret = 0;

    ret += solve(k - 1) % MOD;
    if(k >= 2) ret += solve(k - 2) % MOD;

    return ret % MOD;
}

int solution(int n) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));

    answer = solve(n);

    return answer;
}
