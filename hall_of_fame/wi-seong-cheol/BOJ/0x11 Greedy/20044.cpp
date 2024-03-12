//
//  20044.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 2
 1 7 5 8
 [Output]
 9
 */
// 시간복잡도: O(nlogn)
// 최악시간: 15,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/20044

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = INF;
    for(int i = 0; i < 2 * n; i++) {
        ans = min(ans, v[i] + v[2 * n - i - 1]);
    }
    cout << ans;

	return 0;
}
