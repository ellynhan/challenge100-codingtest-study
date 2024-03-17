//
//  5545.cpp
//  main
//
//  Created by wi_seong on 3/17/24.
//

/*
 [Input]
 3
 12 2
 200
 50
 300
 100
 [Output]
 37
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/5545

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, a, b, c;
int d[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> a >> b >> c;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d + n, greater<int>());
    int sum = c;
    ans = c / a;
    for(int i = 0; i < n; i++) {
        sum += d[i];
        if(ans < sum / (a + b * (i + 1))) {
            ans = sum / (a + b * (i + 1));
        }
    }
    cout << ans;

	return 0;
}
