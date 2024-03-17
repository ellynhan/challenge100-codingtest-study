//
//  2011.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 1111111111
 [Output]
 89
 */
// 시간복잡도: O(n)
// 최악시간: 5,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2011

#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1000000;
string n;
int cache[5001];

int solve(int len) {
    if(len == 0) return 1;
    int& ret = cache[len];
    if(ret != -1) return ret;
    ret = 0;
    if(len >= 1 && n[len - 1] != '0') {
        ret = (ret + solve(len - 1)) % MOD;
    }
    if(len >= 2) {
        if(n[len - 2] == '1' || (n[len - 2] == '2' && n[len - 1] <= '6')) {
            ret = (ret + solve(len - 2)) % MOD;
        }
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    int len = int(n.length());
    cout << solve(len);

	return 0;
}
