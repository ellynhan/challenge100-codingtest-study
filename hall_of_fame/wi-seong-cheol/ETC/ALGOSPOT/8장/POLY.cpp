//
//  POLY.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 3
 2
 4
 92
 [Output]
 2
 19
 4841817
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/POLY

#include <iostream>
#include <cstring>

using namespace std;
const int mod = 10000000;
int t, n;
int cache[101][101];

int solve(int cnt, int first) {
    if(cnt == first) return 1;
    int &ret = cache[cnt][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int second = 1; second <= cnt - first; second++) {
        int add = first + second - 1;
        add *= solve(cnt - first, second);
        add %= mod;
        ret += add;
        ret %= mod;
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            (ans += solve(n, i)) %= mod;
        cout << ans << '\n';
    }

	return 0;
}
