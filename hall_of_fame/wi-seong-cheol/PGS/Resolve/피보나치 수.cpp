//
//  피보나치 수.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 2
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int mod = 1234567;
int cache[100001];

int solve(int k) {
    if(k == 0) return 0;
    if(k == 1) return 1;
    int& ret = cache[k];
    if(ret != -1) return ret;
    return ret = (solve(k - 1) + solve(k - 2)) % mod;
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    int answer = solve(n);
    return answer;
}
