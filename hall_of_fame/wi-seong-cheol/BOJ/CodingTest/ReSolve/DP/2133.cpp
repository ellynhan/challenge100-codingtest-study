//
//  2133.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 2
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 900
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2133

#include <iostream>
#include <cstring>

using namespace std;
int n;
int cache[31];

int solve(int k) {
    if(k == 0) return 1;
    int& ret = cache[k];
    if(ret != -1) return ret;
    ret = 0;
    if(k % 2 == 0) {
        ret += solve(k - 2) * 3;
        for(int i = 4; i <= k; i += 2) {
            ret += solve(k - i) * 2;
        }
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
