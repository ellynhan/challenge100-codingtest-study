//
//  17411.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 10
 3 2 1 6 5 4 10 9 8 7
 [Output]
 3 36
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Platinum 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17411

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int n, lisLen;
int a[1000001], dp[1000001], lis[1000001];
vector<ll> num[1000001], sum[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        int idx = int(lower_bound(lis, lis + lisLen, a[i]) - lis);
        lis[idx] = a[i];
        dp[i] = idx + 1;
        lisLen = max(lisLen, dp[i]);
    }
    cout << lisLen << " ";

    for(int i = 1; i <= lisLen; i++)
        sum[i].push_back(0);

    for(int i = n - 1; i >= 0; i--) {
        int j = 1;
        int len = dp[i];

        if(len < lisLen) {
            int idx = int(upper_bound(num[len + 1].begin(), num[len + 1].end(), a[i]) - num[len + 1].begin());
            j = int(sum[len + 1].back() - sum[len + 1][idx]);
        }
        num[len].push_back(a[i]);
        sum[len].push_back((j + sum[len].back()) % MOD);
    }
    cout << (sum[1].back() + MOD) % MOD << '\n';

	return 0;
}
