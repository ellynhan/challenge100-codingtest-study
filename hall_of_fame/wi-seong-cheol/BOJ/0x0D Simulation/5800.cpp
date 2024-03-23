//
//  5800.cpp
//  main
//
//  Created by wi_seong on 3/18/24.
//

/*
 [Input]
 2
 5 30 25 76 23 78
 6 25 50 70 99 70 90
 [Output]
 Class 1
 Max 78, Min 23, Largest gap 46
 Class 2
 Max 99, Min 25, Largest gap 25
 */
// 시간복잡도: O(nlogn)
// 최악시간: 5,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/5800

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int a[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a, a + n);
        int gap = 0;
        for(int j = 0; j < n - 1; j++) {
            gap = max(gap, a[j + 1] - a[j]);
        }
        int mn = a[0];
        int mx = a[n - 1];

        cout << "Class " << i << '\n';
        cout << "Max " << mx << ", Min " << mn << ", Largest gap " << gap << '\n';
    }

	return 0;
}
