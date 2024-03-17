//
//  1463.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 10
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 3m
// Url: https://www.acmicpc.net/problem/1463

#include <iostream>
#include <cstring>

using namespace std;
int n;
int cache[1000001];

int solve(int k) {
    if(k == 1) return 0;
    int& ret = cache[k];
    if(ret != -1) return ret;
    
    ret = solve(k - 1) + 1;
    if(k % 3 == 0) ret = min(ret, solve(k / 3) + 1);
    if(k % 2 == 0) ret = min(ret, solve(k / 2) + 1);

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << solve(n) << '\n';

	return 0;
}
