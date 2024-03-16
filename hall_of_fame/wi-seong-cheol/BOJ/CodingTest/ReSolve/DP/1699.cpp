//
//  1699.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 7
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 3m
// Url: https://www.acmicpc.net/problem/1699

#include <iostream>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int n;
int cache[100001];

int solve(int k) {
    if(k == 0) return 0;
    int& ret = cache[k];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = 1; i * i <= k; i++) {
        ret = min(ret, solve(k - i * i) + 1);
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << solve(n);

	return 0;
}
