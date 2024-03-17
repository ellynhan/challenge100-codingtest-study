//
//  2170.cpp
//  main
//
//  Created by wi_seong on 3/15/24.
//

/*
 [Input]
 4
 1 3
 2 5
 3 5
 6 7
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 5,000,000
// 난이도: Gold 5
// Timer: 16m
// Url: https://www.acmicpc.net/problem/2170

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int ans = v[0].second - v[0].first;
    int start = v[0].first;
    int end = v[0].second;
    for(int i = 1; i < n; i++) {
        if(v[i].second <= end) continue;
        if(end <= v[i].first) {
            ans += v[i].second - v[i].first;
            start = v[i].first;
            end = v[i].second;
        } else {
            ans += v[i].second - end;
            start = v[i].first;
            end = v[i].second;
        }
    }

    cout << ans;

	return 0;
}
