//
//  11053.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 6
 10 20 10 30 20 50
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Silver 2
// Timer: 3m
// Url: https://www.acmicpc.net/problem/11053

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
        if(v.empty() || v.back() < x) {
            v.push_back(x);
        } else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout << v.size();

	return 0;
}
