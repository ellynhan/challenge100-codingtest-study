//
//  아방가르드 타일링.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/181186#

#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll dp[100001] = { 1, 1, 3, 10, 23, 62, 170 };
ll sum[100002] = { 1, 1, 3, 11, 24, 65, 181 };

int solution(int n) {
    int answer = 0;

    for(int i = 7; i <= n; i++) {
        dp[i] += dp[i - 1] % MOD;
        dp[i] += (dp[i - 2] * 2) % MOD;
        dp[i] += (dp[i - 3] * 5) % MOD;
        dp[i] += (sum[i - 4] * 2) % MOD;
        dp[i] += (sum[i - 5] * 2) % MOD;
        dp[i] += (sum[i - 6] * 4) % MOD;
        dp[i] %= MOD;

        sum[i] = dp[i] + sum[i - 3];
        sum[i] %= MOD;
    }

    answer = dp[n];

    return answer;
}
