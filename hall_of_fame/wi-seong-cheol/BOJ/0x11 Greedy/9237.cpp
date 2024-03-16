//
//  9237.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 6
 39 38 9 35 39 20
 [Output]
 42
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 5
// Timer: 6m
// Url: https://www.acmicpc.net/problem/9237

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, v[i] + i + 2);
    }
    cout << ans;

	return 0;
}
