//
//  1365.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 4
 2 3 4 1
 [Output]
 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500'000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1365

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;

        if(a.empty() || a.back() <= x) {
            a.push_back(x);
        } else {
            *lower_bound(a.begin(), a.end(), x) = x;
        }
    }
    cout << n - a.size();

	return 0;
}
