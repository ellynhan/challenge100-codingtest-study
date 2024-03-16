//
//  2482.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 4 2
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 23m
// Url: https://www.acmicpc.net/problem/2482

#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1e9 + 3;
int n, m;
int cache[1001][1001];

int solve(int cnt, int k) {
    if(k == 1) return cnt;
    if(k > cnt / 2) return 0;
    int& ret = cache[cnt][k];
    if(ret != -1) return ret;

    ret = (solve(cnt - 1, k) + solve(cnt - 2, k - 1)) % MOD;

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    cout << solve(n, m);

	return 0;
}
