//
//  14719.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 4 4
 3 0 1 4
 [Output]
 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14719

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
int a[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < m - 1; i++) {
        int left = 0; int right = 0;

        for(int j = 0; j < i; j++) left = max(left, a[j]);
        for(int j = i + 1; j < m; j++) right = max(right, a[j]);
        ans += max(0, min(left, right) - a[i]);
    }
    cout << ans;

	return 0;
}
