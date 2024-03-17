//
//  3135.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 100 15
 1
 15
 [Output]
 1
 */
// 시간복잡도: O(n)
// 최악시간: 5
// 난이도: Silver 5
// Timer: 1m
// Url: https://www.acmicpc.net/problem/3135

#include <iostream>
#include <algorithm>

using namespace std;
int a, b, n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> a >> b;
    cin >> n;
    int ans = abs(a - b);
    for(int i = 0; i < n; i++) {
        cin >> x;
        ans = min(ans, abs(x - b) + 1);
    }
    cout << ans;

	return 0;
}
