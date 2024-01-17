//
//  2352.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 6
 4 2 6 3 1 5
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 160'000
// 난이도: Gold 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/2352

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
        if(a.empty() || a.back() < x) {
            a.push_back(x);
        } else {
            *lower_bound(a.begin(), a.end(), x) = x;
        }
    }
    cout << a.size();

	return 0;
}
