//
//  ASYMTILING.cpp
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
 0
 2
 913227494
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/ASYMTILING

#include <iostream>
#include <cstring>

using namespace std;
const int mod = 1e9 + 7;
int t, n;
int cache[101];

void precalc() {
    cache[0] = cache[1] = 1;
    for(int i = 2; i <= 100; ++i)
        cache[i] = (cache[i - 1] + cache[i - 2]) % mod;
}

int tiling(int length) { return cache[length]; }

int asymtiling(int length) {
    if(length % 2 == 1)
        return (tiling(length) - tiling(length / 2) + mod) % mod;
    int ret = tiling(length);
    ret = (ret - tiling(length / 2) + mod) % mod;
    ret = (ret - tiling(length / 2 - 1) + mod) % mod;
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    precalc();

    cin >> t;
    while(t--) {
        cin >> n;
        cout << asymtiling(n) << '\n';
    }

	return 0;
}
