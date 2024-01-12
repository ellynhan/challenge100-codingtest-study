//
//  TILING2.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 3
 1
 5
 100
 [Output]
 1
 8
 782204094
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: 하
// Timer: 10m
// Url: https://www.algospot.com/judge/problem/read/TILING2

#include <iostream>
#include <cstring>

using namespace std;
const int mod = 1e9 + 7;
int t, n;
int cache[101];

int solve(int len) {
    int& ret = cache[len];
    if(len == 1) return ret = 1;
    if(len == 2) return ret = 2;
    if(ret != -1) return ret;

    return ret = (solve(len - 1) + solve(len - 2)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    solve(100);

    cin >> t;
    while(t--) {
        cin >> n;
        cout << cache[n] << '\n';
    }

	return 0;
}
