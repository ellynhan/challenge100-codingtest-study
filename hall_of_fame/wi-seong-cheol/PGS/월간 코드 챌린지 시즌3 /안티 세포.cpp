//
//  안티 세포.cpp
//  main
//
//  Created by wi_seong on 2/18/24.
//

// 시간복잡도: O(nlogb)
// 최악시간: 1,800,000
// 난이도: Level 4
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/86054?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
const int MOD = 1e9 + 7;

int binarySearch(const vector<long long>& arr, long long x) {
    int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if(idx == 0 && arr[idx] != x) return -1;
    else if(idx == int(arr.size())) return -1;
    else return idx;
}

int solve(const vector<int>& b) {
    int n = int(b.size());
    int maxb = *max_element(b.begin(), b.end());

    vector<long long> ps = {0, b[0]};
    for (int i = 1; i < n; ++i) {
        ps.push_back(ps.back() + b[i]);
    }

    int maxe = ceil(log2(ps.back()));
    vector<vector<long long>> dp(n, vector<long long>(maxe + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i < n; ++i) {
        for(int e = 0; e <= maxe; e++)
            dp[i][0] += dp[i - 1][e] % MOD;
        dp[i][0] %= MOD;

        for(int e = 1; e <= maxe; ++e) {
            if(dp[i][e - 1] == 0) continue;

            long long target = ps[i + 1] - b[i] * (1LL << (e - 1));
            int jhalf = binarySearch(ps, target);
            if(jhalf <= 0) continue;

            double eprime = log2(b[i] / (double)b[jhalf - 1]) + (e - 1);
            if(eprime < 0 || floor(eprime) != eprime) continue;

            if(!(dp[jhalf - 1][(int)eprime] > 0)) continue;

            target = ps[i + 1] - b[i] * (1LL << e);
            int jfull = binarySearch(ps, target);
            if(jfull == -1) continue;

            if(jfull == 0) dp[i][e] = 1;
            else {
                for(int k = 0; k <= maxe; k++)
                    dp[i][e] += dp[jfull - 1][k] % MOD;
                dp[i][e] %= MOD;
            }
        }
    }

    long long sum = 0;
    for(int e = 0; e <= maxe; e++)
        sum += dp[n - 1][e] % MOD;
    return sum % MOD;
}

vector<int> solution(vector<int> a, vector<int> s) {
    vector<int> answer;
    int n = int(s.size());
    int st = 0;

    for(int i = 0; i < n; i++) {
        int len = s[i];
        vector<int> b(a.begin() + st, a.begin() + st + len);
        st += len;

        int result = solve(b);
        answer.push_back(result);
    }

    return answer;
}
