//
//  9657.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 6
 [Output]
 SK
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/9657

#include <iostream>
#include <cstring>

using namespace std;
int n;
int cache[1001];

int solve(int turn, int k) {
    if(k == 2) return 0;
    if(k < 5) return 1;
    int& ret = cache[k];
    if(ret != -1) return ret;
    int win = solve(turn + 1, k - 1);
    win += solve(turn + 1, k - 3);
    win += solve(turn + 1, k - 4);

    return win == 3 ? ret = 0 : ret = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    if(solve(0, n)) cout << "SK";
    else cout << "CY";

	return 0;
}
