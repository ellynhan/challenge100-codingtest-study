//
//  9251.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 ACAYKP
 CAPCAK
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 18m
// Url: https://www.acmicpc.net/problem/9251

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
string a, b;
int cache[1001][1001];

int solve(int i, int j) {
    if(i == int(a.size()) || j == int(b.size())) return 0;
    int& ret = cache[i][j];
    if(ret != -1) return ret;

    if(a[i] == b[j]) ret = solve(i + 1, j + 1) + 1;
    else ret = max(solve(i + 1, j), solve(i, j + 1));

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> a >> b;
    cout << solve(0, 0);

	return 0;
}
