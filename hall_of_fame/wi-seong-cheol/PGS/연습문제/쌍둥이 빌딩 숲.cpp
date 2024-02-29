//
//  쌍둥이 빌딩 숲.cpp
//  main
//
//  Created by wi_seong on 2/13/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/140105#

#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;
const int MOD = 1e9 + 7;
long long cache[101][101];

long long solve(int h, int count) {
    if(h == 0 || count == 0) return 0;
    if(h == 1 && count == 1) return 1;
    long long &ret = cache[h][count];
    if(ret != -1) return ret;

    ret = solve(h - 1, count - 1) + (solve(h - 1, count) * 2 * (h - 1)) % MOD;

    return ret % MOD;
}

int solution(int n, int count) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));

    answer = solve(n, count);

    return answer;
}
