//
//  LIS.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 3
 4
 1 2 3 4
 8
 5 4 3 2 1 6 7 8
 8
 5 6 7 8 1 2 3 4
 [Output]
 4
 4
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,500
// 난이도: 하
// Timer: 10m
// Url: https://www.acmicpc.net/problem/LIS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, x;
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        a.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(a.empty() || a.back() < x) {
                a.push_back(x);
            } else {
                *lower_bound(a.begin(), a.end(), x) = x;
            }
        }
        cout << a.size() << '\n';
    }

	return 0;
}
