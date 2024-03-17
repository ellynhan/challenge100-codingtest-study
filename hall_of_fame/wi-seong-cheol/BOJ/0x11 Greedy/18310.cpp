//
//  18310.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 4
 5 1 7 9
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/18310

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
    cout << v[(n - 1) / 2];

	return 0;
}
