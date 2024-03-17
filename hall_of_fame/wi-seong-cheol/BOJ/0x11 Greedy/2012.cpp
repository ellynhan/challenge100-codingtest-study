//
//  2012.cpp
//  main
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 5
 1
 5
 3
 1
 2
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 2,500,000
// 난이도: Silver 3
// Timer: 2m
// Url: https://www.acmicpc.net/problem/2012

#include <iostream>
#include <algorithm>
#include <vector>

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
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(v[i] - (i + 1));
    }
    cout << ans;

	return 0;
}
